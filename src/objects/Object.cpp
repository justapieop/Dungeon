//
// Created by JustAPie on 2/8/2025.
//

#include "Object.hpp"
#include "../TextureManager.hpp"

Object::Object(const char *sheet, SDL_Renderer *renderer) {
    this->renderer = renderer;
    this->x = 0;
    this->y = 0;
}

Object::~Object() {
    this->renderer = nullptr;
}

void Object::set_pos(const int x, const int y) {
    this->x = x;
    this->y = y;
}

void Object::render() const {
    SDL_RenderCopy(this->renderer, this->texture, &this->source, & this->dest);
}
