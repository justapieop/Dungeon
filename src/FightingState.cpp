#include "FightingState.hpp"
#include "Constants.hpp"
#include "CurrentStatComponent.hpp"
#include "Game.hpp"
#include "SDL2/SDL.h"
#include "StateManager.hpp"
#include "string"

FightingState::FightingState()
{
    this->is_my_turn = true;
    this->status_text = std::string();
}

FightingState::~FightingState() = default;

void FightingState::update()
{
    this->player = std::any_cast<Entity*>(this->get_args()[0]);
    this->enemy = std::any_cast<Entity*>(this->get_args()[1]);
    CurrentStatComponent *player_current = &this->player->get_component<CurrentStatComponent>();
    CurrentStatComponent *enemy_current = &this->enemy->get_component<CurrentStatComponent>();

    const Uint8 *key_states = SDL_GetKeyboardState(nullptr);

    if (key_states[SDL_SCANCODE_A])
    {
        if (!this->my_turn()) return;
        enemy_current->set_hp(enemy_current->get_hp() - (BASE_DAMAGE + 1.36 * player_current->get_atk() - enemy_current->get_def()));
        return;
    }

    if (player_current->get_hp() == 0.0f)
    {
        Game::state_manager->set_state(GameState::GAME_OVER);
        return;
    }
    if (enemy_current->get_hp() == 0.0f)
    {
        Game::state_manager->set_state(GameState::VICTORY);
    }
}

void FightingState::draw()
{

}

void FightingState::set_my_turn(bool is_my_turn)
{
    this->is_my_turn = is_my_turn;
}

bool FightingState::my_turn() const
{
    return this->is_my_turn;
}
