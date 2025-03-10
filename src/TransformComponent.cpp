//
// Created by JustAPie on 08/03/2025.
//
#include "TransformComponent.hpp"

#include "Game.hpp"

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
    const Uint8* key_state = SDL_GetKeyboardState(nullptr);
    if (key_state[SDL_SCANCODE_W])
    {
        this->pos->subtract(Vec2D(0, 1).multiply(this->get_speed()));
    }
    else if (key_state[SDL_SCANCODE_S])
    {
        this->pos->add(Vec2D(0, 1).multiply(this->get_speed()));
    }
    else if (key_state[SDL_SCANCODE_A])
    {
        this->pos->subtract(Vec2D(1, 0).multiply(this->get_speed()));
    }
    else if (key_state[SDL_SCANCODE_D])
    {
        this->pos->add(Vec2D(1, 0).multiply(this->get_speed()));
    }

    if (key_state[SDL_SCANCODE_W])
    {
        this->pos->subtract(Vec2D(0, 1).multiply(this->get_speed()));
    }
    else if (key_state[SDL_SCANCODE_S])
    {
        this->pos->add(Vec2D(0, 1).multiply(this->get_speed()));
    }
    else if (key_state[SDL_SCANCODE_A])
    {
        this->pos->subtract(Vec2D(1, 0).multiply(this->get_speed()));
    }
    else if (key_state[SDL_SCANCODE_D])
    {
        this->pos->add(Vec2D(1, 0).multiply(this->get_speed()));
    }
}


Vec2D* TransformComponent::get_pos() const
{
    return this->pos;
}
