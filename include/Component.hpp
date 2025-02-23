//
// Created by JustAPie on 2/23/2025.
//

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class Entity;

#include "Entity.hpp"

class Component {
public:
    Component();
    virtual ~Component();

    virtual void update();
    virtual void draw();
private:
    Entity* entity;
};

#endif //COMPONENT_HPP
