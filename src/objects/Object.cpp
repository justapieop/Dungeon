//
// Created by JustAPie on 2/8/2025.
//

#include "../../include/Object.hpp"
#include "../../include/TextureManager.hpp"
#include "string"

Object::Object(const std::string& sheet, SDL_Renderer *renderer) {
    this->renderer = renderer;
    this->texture = TextureManager::load_texture(sheet, this->renderer);
}

Object::~Object() {
    this->renderer = nullptr;
    this->texture = nullptr;
}

void Object::set_pos_src(const int x, const int y) {
    this->source.x = x;
    this->source.y = y;
}

void Object::set_size_src(const int w, const int h) {
    this->source.w = w;
    this->source.h = h;
}

void Object::set_pos_dest(const int x, const int y) {
    this->dest.x = x;
    this->dest.y = y;
}

void Object::set_size_dest(const int w, const int h) {
    this->dest.w = w;
    this->dest.h = h;
}




void Object::update() {

}


void Object::render() const {
    SDL_RenderCopy(this->renderer, this->texture, &this->source, &this->dest);
}
