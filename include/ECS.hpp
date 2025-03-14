//
// Created by JustAPie on 06/03/2025.
// Reference: Let's Make Games
//

#ifndef ECS_HPP
#define ECS_HPP
#include "memory"
#include "iostream"
#include "bitset"
#include "vector"

class Component;
class Entity;

using ComponentId = std::size_t;

inline ComponentId get_component_id()
{
    static ComponentId last = 0;
    return last++;
}

template <typename T>
ComponentId get_component_id() noexcept
{
    static ComponentId type_id = get_component_id();
    return type_id;
}

constexpr std::size_t max_components = 32;

using ComponentBitset = std::bitset<max_components>;
using ComponentArray = std::array<Component*, max_components>;


class Component
{
public:
    virtual ~Component() = default;
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    Entity* entity{};
};

class Entity
{
public:
    Entity() = default;
    ~Entity() = default;

    void update()
    {
        for (const auto& c : this->components) c->update();
    }
    void draw()
    {
        for (const auto& c : this->components) c->draw();
    }
    void destroy()
    {
        this->is_active = false;
    }

    template <typename T>
    [[nodiscard]] bool has_component() const
    {
        return this->component_bitset[get_component_id<T>()];
    }

    template <typename T, typename... TArgs>
    T& add_components(TArgs&&... args)
    {
        T* c(new T(std::forward<TArgs>(args)...));
        c->entity = this;
        std::unique_ptr<Component> p_component{c};
        this->components.emplace_back(std::move(p_component));
        this->component_array[get_component_id<T>()] = c;

        this->component_bitset[get_component_id<T>()] = true;
        c->init();

        return *c;
    }

    template <typename T>
    T& get_component() const
    {
        auto p(this->component_array[get_component_id<T>()]);
        return *static_cast<T*>(p);
    }


    [[nodiscard]] bool active() const
    {
        return this->is_active;
    }

private:
    bool is_active{};
    std::vector<std::unique_ptr<Component>> components{};

    ComponentArray component_array{};
    ComponentBitset component_bitset{};
};

class ComponentManager
{
public:
    void update()
    {
        for (const auto& e : entities) e->update();
    }
    void draw()
    {
        for (const auto& e : entities) e->draw();
    }
    void refresh()
    {
        std::erase_if(this->entities,
                  [](const Entity* entity)
                  {
                      return !entity->active();
                  }
    );
    }

    Entity& add_entity()
    {
        auto* e = new Entity();
        this->entities.push_back(e);
        return *e;
    }

private:
    std::vector<Entity*> entities;
};

#endif //ECS_HPP
