#include "TransformComponent.hpp"
#include "Constants.hpp"
#include "Game.hpp"
#include "InputHandler.hpp"
#include "Vec2D.hpp"

TransformComponent::TransformComponent()
{
    this->pos = new Vec2D(0.0f, 0.0f);
}

TransformComponent::TransformComponent(const float x, const float y)
{
    this->pos = new Vec2D(x, y);
}

void TransformComponent::set_pos(const float x, const float y) const
{
    this->pos->set_pos(x, y);
}

void TransformComponent::init()
{
    if (!this->entity->has_component<InputHandler>())
    {
        this->entity->add_components<InputHandler>();
    }
    this->input_handler = &this->entity->get_component<InputHandler>();
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


Vec2D& TransformComponent::get_pos() const
{
    return *this->pos;
}

[[nodiscard]] InputHandler *TransformComponent::get_input() const
{
    return this->input_handler;
}
