//
// Created by JustAPie on 2/18/2025.
//
#include "Object.hpp"
#include "Game.hpp"
#include "TextureManager.hpp"

Object::Object(const std::string& sheet) {
    this->texture = TextureManager::load_texture(sheet);
}

Object::~Object() {
    this->texture = nullptr;
    this->x = this->y = 0;
}

void Object::set_pos(const int x, const int y) {
    this->x = x;
    this->y = y;

    this->dest.x = this->x;
    this->dest.y = this->y;
}

void Object::set_size(const int w, const int h) {
    this->src.w = w;
    this->src.h = h;
    this->dest.w = w;
    this->dest.h = h;
}

void Object::update() {
    this->x++;
    this->y++;
    this->set_pos(this->x, this->y);
}


void Object::render() const {
    SDL_RenderCopy(Game::renderer, this->texture, &this->src, &this->dest);
}
