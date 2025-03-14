//
// Created by JustAPie on 08/03/2025.
//
#include "TransformComponent.hpp"

#include "Constants.hpp"
#include "Game.hpp"

TransformComponent::TransformComponent()
{
    this->pos = new Vec2D(0.0f, 0.0f);
    this->h = this->w = 32;
}

TransformComponent::TransformComponent(const float x, const float y)
{
    this->pos = new Vec2D(x, y);
    this->h = this->w = 32;
}

TransformComponent::TransformComponent(const float x, const float y, const int w, const int h)
{
    this->pos = new Vec2D(x, y);
    this->h = h;
    this->w = w;
}

void TransformComponent::set_pos(const float x, const float y) const
{
    this->pos->set_pos(x, y);
}

void TransformComponent::init()
{
}


void TransformComponent::draw()
{
}

float TransformComponent::get_speed() const
{
    return this->speed;
}

void TransformComponent::set_speed(const float speed)
{
    this->speed = speed;
}


void TransformComponent::update()
{

}

int TransformComponent::get_h() const
{
    return this->h;
}

int TransformComponent::get_w() const
{
    return this->w;
}


Vec2D* TransformComponent::get_pos() const
{
    return this->pos;
}
