//
// Created by JustAPie on 08/03/2025.
//
#include "TransformComponent.hpp"

TransformComponent::TransformComponent()
{
    this->pos = new Vec2D(0.0f, 0.0f);
}


void TransformComponent::set_pos(const float x, const float y) const
{
    this->pos->set_pos(x, y);
}

TransformComponent::TransformComponent(const float x, const float y)
{
    this->pos = new Vec2D(x, y);
}

void TransformComponent::init()
{
}


void TransformComponent::draw()
{
}

void TransformComponent::update()
{
    this->get_pos()->add(Vec2D(1.0f, 1.0f));
}


Vec2D* TransformComponent::get_pos() const
{
    return this->pos;
}
