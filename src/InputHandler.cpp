//
// Created by JustAPie on 14/03/2025.
//
#include "InputHandler.hpp"

#include "Constants.hpp"
#include "SDL2/SDL.h"

InputHandler::InputHandler() = default;

InputHandler::~InputHandler() = default;

void InputHandler::draw()
{

}

void InputHandler::init()
{
    this->transform_component = &this->entity->get_component<TransformComponent>();
}

void InputHandler::update()
{
    if (const Uint8* key_state = SDL_GetKeyboardState(nullptr); key_state[SDL_SCANCODE_W])
    {
        this->transform_component->get_pos()->subtract(Vec2D(0.0f, 1.0f).multiply(this->transform_component->get_speed()));
        if (key_state[SDL_SCANCODE_A])
            this->transform_component->get_pos()->subtract(Vec2D(1.0f, 0.0f).multiply(this->transform_component->get_speed()));
        if (key_state[SDL_SCANCODE_D])
            this->transform_component->get_pos()->add(Vec2D(1.0f, 0.0f).multiply(this->transform_component->get_speed()));
    }
    else if (key_state[SDL_SCANCODE_S])
    {
        this->transform_component->get_pos()->add(Vec2D(0.0f, 1.0f).multiply(this->transform_component->get_speed()));
        if (key_state[SDL_SCANCODE_A])
            this->transform_component->get_pos()->subtract(Vec2D(1.0f, 0.0f).multiply(this->transform_component->get_speed()));
        if (key_state[SDL_SCANCODE_D])
            this->transform_component->get_pos()->add(Vec2D(1.0f, 0.0f).multiply(this->transform_component->get_speed()));
    }
    else if (key_state[SDL_SCANCODE_A])
    {
        this->transform_component->get_pos()->subtract(Vec2D(1.0f, 0.0f).multiply(this->transform_component->get_speed()));
        if (key_state[SDL_SCANCODE_W])
            this->transform_component->get_pos()->subtract(Vec2D(0.0f, 1.0f).multiply(this->transform_component->get_speed()));
        if (key_state[SDL_SCANCODE_S])
            this->transform_component->get_pos()->add(Vec2D(0.0f, 1.0f).multiply(this->transform_component->get_speed()));
    }
    else if (key_state[SDL_SCANCODE_D])
    {
        this->transform_component->get_pos()->add(Vec2D(1.0f, 0.0f).multiply(this->transform_component->get_speed()));
        if (key_state[SDL_SCANCODE_W])
            this->transform_component->get_pos()->subtract(Vec2D(0.0f, 1.0f).multiply(this->transform_component->get_speed()));
        if (key_state[SDL_SCANCODE_S])
            this->transform_component->get_pos()->add(Vec2D(0.0f, 1.0f).multiply(this->transform_component->get_speed()));
    }

    if (this->transform_component->get_pos()->get_x() < 0)
        this->transform_component->get_pos()->set_pos(0.0f, this->transform_component->get_pos()->get_y());
    if (this->transform_component->get_pos()->get_y() < 0)
        this->transform_component->get_pos()->set_pos(this->transform_component->get_pos()->get_x(), 0.0f);
    if (this->transform_component->get_pos()->get_y() >= SCREEN_HEIGHT - 32)
        this->transform_component->get_pos()->set_pos(this->transform_component->get_pos()->get_x(), static_cast<float>(SCREEN_HEIGHT - 32));
    if (this->transform_component->get_pos()->get_x() >= SCREEN_WIDTH - 32)
        this->transform_component->get_pos()->set_pos(static_cast<float>(SCREEN_WIDTH - 32), this->transform_component->get_pos()->get_y());
}


