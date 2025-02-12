//
// Created by JustAPie on 2/10/2025.
//

#include "../../include/SceneManager.hpp"

SceneManager::SceneManager(SDL_Renderer* renderer) {
    this->renderer = renderer;
}

SceneManager::~SceneManager() {
    this->current = nullptr;
}

void SceneManager::set_scene(Scene *scene) {
    this->current = nullptr;
    this->current = scene;
}

void SceneManager::render() const {
    this->current->render();
}
