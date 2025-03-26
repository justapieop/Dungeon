#include "StateManager.hpp"
#include "State.hpp"
#include "map"
#include "memory"

StateManager::StateManager()
{
    this->states = std::map<int, State*>();
}

void StateManager::update()
{
    this->get_current_state().update();
}

void StateManager::draw()
{
    this->get_current_state().draw();
}

State& StateManager::get_current_state()
{
    return *this->get_states()[this->get_state()];
}

std::map<int, State*>& StateManager::get_states()
{
    return this->states;
}

int StateManager::get_state() const
{
    return this->state;
}

void StateManager::set_state(int state)
{
    this->state = state;
}
