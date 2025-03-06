//
// Created by JustAPie on 06/03/2025.
// Reference: Let's Make Games
//

#ifndef ECS_HPP
#define ECS_HPP
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
using ComponentArray = std::vector<Component*>;


class Component
{
public:
    virtual void init();
    virtual void update();
    virtual void draw();
    Entity* get_entity();

private:
    Entity* entity{};
};

class Entity
{
public:
    Entity();
    ~Entity();

    void update();
    void draw();
    void destroy();

    template <typename T>
    [[nodiscard]] bool has_component() const;

    template <typename T, typename... TArgs>
    T& add_components(TArgs&&... args);

    template <typename T>
    T& get_component() const;


    [[nodiscard]] bool active() const;

private:
    bool is_active{};
    std::vector<Component*> components;

    ComponentArray component_array;
    ComponentBitset component_bitset;
};

class ComponentManager
{
public:
    void update();
    void draw();
    void refresh();

    Entity& add_entity();

private:
    std::vector<Entity*> entities;
};

#endif //ECS_HPP
