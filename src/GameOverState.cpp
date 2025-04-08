#include "GameOverState.hpp"
#include "Game.hpp"
#include "StateManager.hpp"

GameOverState::GameOverState() {
    this->header = new Text(256, 128, 120, 16, "You lost");
    this->exit = new Text(256, 250, 256, 16, "Press ESC to quit");

    this->header->create_text();
    this->exit->create_text();
}

GameOverState::~GameOverState() = default;

void GameOverState::update() {
    if (Game::event.type != SDL_KEYDOWN)
        return;

    if (Game::event.key.keysym.sym == SDLK_ESCAPE) {
        Game::force_stop();
    }
}

void GameOverState::draw() {
    this->header->draw();
    this->exit->draw();
}
