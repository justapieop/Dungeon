//
// Created by JustAPie on 2/23/2025.
//
#include "Entity.hpp"

bool Entity::active() const {
    return this->is_active;
}

void Entity::destroy() {
    this->is_active = false;
}

void Entity::update() {
    for (const auto & component : this->components) component->update();
}


void Entity::draw() {
    for (const auto & component : this->components) component->draw();
}

template<typename T>
bool Entity::has_component() const {
    return this->component_bitset[IdStore::get_id<T>()];
}

template<typename T, typename... TArgs>
T &Entity::add_components(TArgs &&... args) {
    T* c(new T(std::forward<TArgs>(args)...));
    c->entity = this;
    this->components.emplace_back(c);

    this->unique_components[IdStore::get_id<T>()] = c;
    this->component_bitset[IdStore::get_id<T>()] = true;

    c->init();
    return *c;
}

template<typename T>
T &Entity::get_components() {
    auto ptr(this->unique_components[IdStore::get_id<T>()]);
    return *static_cast<T>(ptr);
}
