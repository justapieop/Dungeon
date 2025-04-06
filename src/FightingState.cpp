#include "FightingState.hpp"
#include "Battle.hpp"
#include "BattleUI.hpp"
#include "Game.hpp"
#include "SDL2/SDL.h"
#include "StateManager.hpp"
#include "string"

FightingState::FightingState() {
    this->status_text = std::string();
    this->ui = new BattleUI(*new Battle());
}

FightingState::~FightingState() = default;

void FightingState::update() {
    this->player = std::any_cast<Entity*>(this->get_args()[0]);
    this->enemy = std::any_cast<Entity*>(this->get_args()[1]);

    this->ui->get_battle().set_entities(*this->player, *this->enemy);

    if (const Uint8* key_states = SDL_GetKeyboardState(nullptr);
        key_states[SDL_SCANCODE_ESCAPE]) {
        Game::state_manager->set_state(PAUSED);
        return;
    }

    switch (this->ui->get_battle().determine()) {
        case ENEMY:
            Game::state_manager->set_state(GAME_OVER);
            break;
        case PLAYER:
            Game::state_manager->set_state(VICTORY);
            break;
        default:
            break;
    }
    this->ui->update();
}

void FightingState::draw() { this->ui->draw(); }
