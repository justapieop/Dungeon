//
// Created by JustAPie on 14/03/2025.
//
#include "CollisionComponent.hpp"

CollisionComponent::CollisionComponent()
{
    if (!this->entity->has_component<TransformComponent>())
    {
        this->entity->add_components<TransformComponent>();
    }
    this->transform_component = &this->entity->get_component<TransformComponent>();
}

CollisionComponent::~CollisionComponent() = default;

void CollisionComponent::draw()
{

}

void CollisionComponent::init()
{

}

void CollisionComponent::update()
{
    this->collider.x = static_cast<int>(this->transform_component->get_pos()->get_x());
    this->collider.y = static_cast<int>(this->transform_component->get_pos()->get_y());
    this->collider.w = this->transform_component->get_w();
    this->collider.h = this->transform_component->get_h();
}
