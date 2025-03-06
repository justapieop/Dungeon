//
// Created by JustAPie on 06/03/2025.
//
#include "PositionComponent.hpp"

void PositionComponent::init()
{
    this->x = this->y = 0;
}

void PositionComponent::update()
{
    this->set_pos(this->x++, this->y++);
}


void PositionComponent::draw()
{
}


int PositionComponent::get_x() const
{
    return this->x;
}

int PositionComponent::get_y() const
{
    return this->y;
}

void PositionComponent::set_pos(const int x, const int y)
{
    this->x = x;
    this->y = y;
}
