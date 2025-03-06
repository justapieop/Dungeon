//
// Created by JustAPie on 06/03/2025.
// Reference: Let's Make Games
//

#include "memory"
#include "ECS.hpp"
Entity::Entity() = default;

Entity::~Entity() = default;


void Entity::update()
{
    for (const auto& c : this->components) c->update();
}

void Entity::draw()
{
    for (const auto& c : this->components) c->draw();
}

void Entity::destroy()
{
    this->is_active = false;
}


template <typename T>
bool Entity::has_component() const
{
    return this->component_bitset[get_component_id<T>];
}

template <typename T, typename... TArgs>
T& Entity::add_components(TArgs&&... args)
{
    T* c(new T(std::forward<TArgs>(args)...));
    c->entity = this;
    Component* p_component{c};
    this->components.emplace_back(p_component);
    this->component_array[get_component_id<T>()] = c;

    this->component_bitset[get_component_id<T>()] = true;
    c->init();

    return *c;
}

template <typename T>
T& Entity::get_component() const
{
    auto p(this->component_array[get_component_id<T>()]);
    return *static_cast<T*>(p);
}


bool Entity::active() const
{
    return this->is_active;
}
