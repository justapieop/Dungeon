#include "MenuState.hpp"
#include "Game.hpp"
#include "StateManager.hpp"
#include "Text.hpp"

MenuState::MenuState()
{
    this->title_txt = new Text(256, 128, 256, 16, "Press SPACEBAR to start");
    this->exit_txt = new Text(256, 256, 256, 16, "Press ESC to quit");

    this->title_txt->create_text();
    this->exit_txt->create_text();
}

MenuState::~MenuState() = default;

void MenuState::update()
{
    if (Game::event.type != SDL_KEYDOWN) return;

    switch (Game::event.key.keysym.sym)
    {
        case SDLK_SPACE:
            Game::state_manager->set_state(GameState::PLAYING);
            break;
        case SDLK_ESCAPE:
            Game::force_stop();
            break;
        default:
            break;
    }
}

void MenuState::draw()
{
    this->title_txt->draw();
    this->exit_txt->draw();
}
