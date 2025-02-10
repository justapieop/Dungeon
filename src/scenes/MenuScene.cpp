//
// Created by JustAPie on 2/10/2025.
//

#include "MenuScene.hpp"

MenuScene::MenuScene(SDL_Renderer *renderer): Scene(renderer) {
}

MenuScene::~MenuScene() = default;

void MenuScene::update() {

}

void MenuScene::set_next_scene() {

}

void MenuScene::render() {
    this->set_bg("assets/bg.png", 0, 0, 1366, 768);
    this->get_bg()->render();
}
