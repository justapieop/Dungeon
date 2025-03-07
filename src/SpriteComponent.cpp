//
// Created by JustAPie on 07/03/2025.
//
#include "SpriteComponent.hpp"

#include "TextureManager.hpp"

SpriteComponent::SpriteComponent() = default;
SpriteComponent::SpriteComponent(const std::string& path)
{
    this->texture = TextureManager::load_texture(path);
}

void SpriteComponent::draw()
{
    TextureManager::draw(this->texture, this->src, this->dest);
}

void SpriteComponent::update()
{
    this->dest.x = this->position_component->get_x();
    this->dest.y = this->position_component->get_y();
}

void SpriteComponent::init()
{
    this->position_component = &this->entity->get_component<PositionComponent>();
    this->src.x = this->src.y = 0;
    this->src.w = this->src.h = 16;
    this->dest.w = this->dest.h = 32;
}


