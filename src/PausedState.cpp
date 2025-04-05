#include "PausedState.hpp"
#include "Game.hpp"
#include "StateManager.hpp"
#include "Text.hpp"

PausedState::PausedState() {
    this->title_txt = new Text(256, 128, 256, 16, "Press ENTER to continue");
    this->exit_txt = new Text(256, 256, 256, 16, "Press ESC to continue");

    this->title_txt->create_text();
    this->exit_txt->create_text();
}

PausedState::~PausedState() = default;

void PausedState::update() {
    if (Game::event.type != SDL_KEYDOWN)
        return;
    switch (Game::event.key.keysym.sym) {
    case 13:
        Game::state_manager->set_state(
            Game::state_manager->get_previous_state());
        break;
    case SDLK_ESCAPE:
        Game::state_manager->set_state(GameState::MENU);
        break;
    default:
        break;
    }
}

void PausedState::draw() {
    this->title_txt->draw();
    this->exit_txt->draw();
}
