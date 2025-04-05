#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP
#include "FightingState.hpp"
#include "MenuState.hpp"
#include "PausedState.hpp"
#include "PlayingState.hpp"
#include "State.hpp"
#include "map"

enum GameState
{
    MENU = 0,
    PLAYING = 1,
    PAUSED = 2,
    FIGHTING = 3,
    GAME_OVER = 4,
    VICTORY = 5,
};

class StateManager
{
public:
    StateManager();
    ~StateManager();
    template <typename... TArgs>
    inline void set_state(const GameState state, TArgs&&... args)
    {
        bool set_prev = this->previous_state == state;
        this->previous_state = this->state;
        this->state = state;
        State *obj = nullptr;
        if (!this->states.count(state))
        {
            switch (state)
            {
                case GameState::PLAYING:
                    obj = new PlayingState();
                    break;
                case GameState::MENU:
                    obj = new MenuState();
                    break;
                case GameState::PAUSED:
                    obj = new PausedState();
                    break;
                case GameState::FIGHTING:
                    obj = new FightingState();
                    break;
                default:
                    return;
            }
            this->states[this->state] = obj;
        }

        obj = this->states[this->state];

        if (!set_prev)
        {
            obj->get_args().clear();
            (obj->get_args().push_back(std::forward<TArgs>(args)), ...);
        }
    }

    State& get_current_state_obj();
    State& get_previous_state_obj();
    void update();
    void draw();
    std::map<int, State*>& get_states();
    GameState get_state() const;
    GameState get_previous_state() const;
private:
    std::map<int, State*> states;
    GameState state, previous_state;
};
#endif //STATEMANAGER_HPP
