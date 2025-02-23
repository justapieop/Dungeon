//
// Created by JustAPie on 2/23/2025.
//

#ifndef COMPONENTMANAGER_HPP
#define COMPONENTMANAGER_HPP
#include "Entity.hpp"
#include "vector"

class ComponentManager {
public:
    ComponentManager();
    ~ComponentManager();

    void update();
    void draw();
    void refresh();
    Entity& add_entity();
private:
    std::vector<Entity*> entities;
};

#endif //COMPONENTMANAGER_HPP
