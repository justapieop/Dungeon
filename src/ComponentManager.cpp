//
// Created by JustAPie on 2/23/2025.
//
#include "ComponentManager.hpp"
#include "algorithm"

void ComponentManager::draw() {
    for (const auto & entity : this->entities) entity->draw();
}

void ComponentManager::update() {
    for (const auto & entity : this->entities) entity->update();
}

void ComponentManager::refresh() {
    this->entities.erase(std::remove_if(this->entities.begin(), this->entities.end(), [](const Entity* e) {
        return !e->active();
    }), this->entities.end());
}

Entity &ComponentManager::add_entity() {
    auto* e = new Entity();
    this->entities.emplace_back(e);
    return *e;
}
