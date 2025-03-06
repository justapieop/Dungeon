//
// Created by JustAPie on 06/03/2025.
//
#include "ECS.hpp"

void ComponentManager::draw()
{
    for (const auto& e : entities) e->draw();
}

void ComponentManager::update()
{
    for (const auto& e : entities) e->update();
}

void ComponentManager::refresh()
{
    std::erase_if(this->entities,
                  [](const Entity* entity)
                  {
                      return !entity->active();
                  }
    );
}

Entity& ComponentManager::add_entity()
{
    auto* e = new Entity();
    this->entities.push_back(e);
    return *e;
}
