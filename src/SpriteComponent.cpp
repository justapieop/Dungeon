#include "SpriteComponent.hpp"
#include "TextureManager.hpp"
#include "SDL2/SDL.h"
#include "string"

SpriteComponent::SpriteComponent() = default;
SpriteComponent::SpriteComponent(const std::string& path) {
    this->texture = TextureManager::load_texture(path);
    this->path = path;
}

void SpriteComponent::draw() {
    TextureManager::draw_f(this->texture, this->src, this->dest);
}

void SpriteComponent::update() {
    this->dest.x = static_cast<int>(this->transform->get_pos().get_x());
    this->dest.y = static_cast<int>(this->transform->get_pos().get_y());
}

void SpriteComponent::set_texture(SDL_Texture* texture) {
    this->texture = texture;
}

void SpriteComponent::init() {
    this->transform = &this->entity->get_component<TransformComponent>();
    this->transform->set_speed(1.2f);
    this->src.x = this->src.y = 0;
    this->src.w = this->src.h = 16;
    this->dest.w = this->dest.h = 32;
}

SDL_FRect& SpriteComponent::get_rect() { return this->dest; }

std::string& SpriteComponent::get_path() {
    return this->path;
}
