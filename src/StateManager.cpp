#include "StateManager.hpp"
#include "GameOverState.hpp"
#include "MenuState.hpp"
#include "PausedState.hpp"
#include "PlayingState.hpp"
#include "State.hpp"
#include "map"
#include "memory"
#include "utility"

StateManager::StateManager()
{
    this->states = std::map<int, State*>();
    this->state = this->previous_state = GameState::MENU;
}

void StateManager::update()
{
    this->get_current_state_obj().update();
}

void StateManager::draw()
{
    this->get_current_state_obj().draw();
}

State& StateManager::get_current_state_obj()
{
    return *this->get_states()[this->get_state()];
}

State& StateManager::get_previous_state_obj()
{
    return *this->get_states()[this->get_previous_state()];
}

std::map<int, State*>& StateManager::get_states()
{
    return this->states;
}

GameState StateManager::get_state() const
{
    return this->state;
}

GameState StateManager::get_previous_state() const
{
    return this->previous_state;
}
