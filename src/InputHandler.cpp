#include "InputHandler.hpp"
#include "Constants.hpp"
#include "SDL2/SDL.h"
#include "Vec2D.hpp"

InputHandler::InputHandler() = default;

InputHandler::~InputHandler() = default;

void InputHandler::draw()
{

}

void InputHandler::init()
{
    this->movement = new Vec2D();
}

void InputHandler::update()
{
    const Uint8* key_state = SDL_GetKeyboardState(nullptr);

    if (key_state[SDL_SCANCODE_W])
        this->movement->subtract(Vec2D(0.0, 1.0f));

    if (key_state[SDL_SCANCODE_S])
        this->movement->add(Vec2D(0.0f, 1.0f));

    if (key_state[SDL_SCANCODE_A])
        this->movement->subtract(Vec2D(1.0f, 0.0f));

    if (key_state[SDL_SCANCODE_D])
        this->movement->add(Vec2D(1.0f, 0.0f));

    this->movement->normalize();
}

Vec2D& InputHandler::get_movement() const
{
    Vec2D *t = new Vec2D(this->movement->get_x(), this->movement->get_y());
    this->movement->multiply(0.0f);
    return *t;
}
