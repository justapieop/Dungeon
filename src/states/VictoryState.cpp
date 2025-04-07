#include "../../include/VictoryState.hpp"
#include "../../include/Game.hpp"

VictoryState::VictoryState() {
    this->title = new Text(256, 128, 120, 16, "You won");
    this->exit = new Text(256, 250, 256, 16, "Press ESC to quit");

    this->title->create_text();
    this->exit->create_text();
}

VictoryState::~VictoryState() = default;

void VictoryState::draw() {
    this->title->draw();
    this->exit->draw();
}

void VictoryState::update() {
    if (Game::event.type != SDL_KEYDOWN)
        return;

    if (Game::event.key.keysym.sym == SDLK_ESCAPE) {
        Game::force_stop();
    }
}

