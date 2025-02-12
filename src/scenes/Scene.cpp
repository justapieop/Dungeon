//
// Created by JustAPie on 2/9/2025.
//

#include "Scene.hpp"
#include "string"

Scene::Scene(SDL_Renderer* renderer) {
    this->renderer = renderer;
}

Scene::~Scene() {
    this->renderer = nullptr;
    this->bg = nullptr;
}

void Scene::set_bg(const std::string &path, const int x, const int y, const int w, const int h) {
    this->bg = new Object(path, this->renderer);
    this->bg->set_pos_src(x, y);
    this->bg->set_size_src(w, h);
    this->bg->set_pos_dest(x, y);
    this->bg->set_size_dest(w, h);
}



