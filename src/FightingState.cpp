#include "FightingState.hpp"
#include "CurrentStatComponent.hpp"
#include "Game.hpp"
#include "SDL2/SDL.h"
#include "SDL_events.h"
#include "StateManager.hpp"

FightingState::FightingState()
{
    this->is_my_turn = true;
}

FightingState::~FightingState() = default;

void FightingState::update()
{
    this->player = std::any_cast<Entity*>(this->get_args()[0]);
    this->enemy = std::any_cast<Entity*>(this->get_args()[1]);
    switch (Game::event.type)
    {
        case SDL_KEYDOWN:
            if (Game::event.key.keysym.sym == SDLK_a)
            {
                return;
            }
            break;
        default:
            break;
    }

    if (this->player->get_component<CurrentStatComponent>().get_hp() == 0.0f)
    {
        Game::state_manager->set_state(GameState::GAME_OVER);
        return;
    }
    if (this->enemy->get_component<CurrentStatComponent>().get_hp() == 0.0f)
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
