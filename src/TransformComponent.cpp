//
// Created by JustAPie on 08/03/2025.
//
#include "TransformComponent.hpp"

#include "Constants.hpp"
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
    if (const Uint8* key_state = SDL_GetKeyboardState(nullptr); key_state[SDL_SCANCODE_W])
    {
        this->pos->subtract(Vec2D(0.0f, 1.0f).multiply(this->get_speed()));
        if (key_state[SDL_SCANCODE_A])
            this->pos->subtract(Vec2D(1.0f, 0.0f).multiply(this->get_speed()));
        if (key_state[SDL_SCANCODE_D])
            this->pos->add(Vec2D(1.0f, 0.0f).multiply(this->get_speed()));
    }
    else if (key_state[SDL_SCANCODE_S])
    {
        this->pos->add(Vec2D(0.0f, 1.0f).multiply(this->get_speed()));
        if (key_state[SDL_SCANCODE_A])
            this->pos->subtract(Vec2D(1.0f, 0.0f).multiply(this->get_speed()));
        if (key_state[SDL_SCANCODE_D])
            this->pos->add(Vec2D(1.0f, 0.0f).multiply(this->get_speed()));
    }
    else if (key_state[SDL_SCANCODE_A])
    {
        this->pos->subtract(Vec2D(1.0f, 0.0f).multiply(this->get_speed()));
        if (key_state[SDL_SCANCODE_W])
            this->pos->subtract(Vec2D(0.0f, 1.0f).multiply(this->get_speed()));
        if (key_state[SDL_SCANCODE_S])
            this->pos->add(Vec2D(0.0f, 1.0f).multiply(this->get_speed()));
    }
    else if (key_state[SDL_SCANCODE_D])
    {
        this->pos->add(Vec2D(1.0f, 0.0f).multiply(this->get_speed()));
        if (key_state[SDL_SCANCODE_W])
            this->pos->subtract(Vec2D(0.0f, 1.0f).multiply(this->get_speed()));
        if (key_state[SDL_SCANCODE_S])
            this->pos->add(Vec2D(0.0f, 1.0f).multiply(this->get_speed()));
    }

    if (this->get_pos()->get_x() < 0) this->get_pos()->set_pos(0.0f, this->get_pos()->get_y());
    if (this->get_pos()->get_y() < 0) this->get_pos()->set_pos(this->get_pos()->get_x(), 0.0f);
    if (this->get_pos()->get_y() >= SCREEN_HEIGHT - 32) this->get_pos()->set_pos(this->get_pos()->get_x(), static_cast<float>(SCREEN_HEIGHT - 32));
    if (this->get_pos()->get_x() >= SCREEN_WIDTH - 32) this->get_pos()->set_pos(static_cast<float>(SCREEN_WIDTH - 32), this->get_pos()->get_y());
}


Vec2D* TransformComponent::get_pos() const
{
    return this->pos;
}
