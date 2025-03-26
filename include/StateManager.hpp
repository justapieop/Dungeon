#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP
#include "State.hpp"
#include "map"

class StateManager
{
public:
    StateManager();
    ~StateManager();

    int get_state() const;
    void set_state(int state);
    State& get_current_state();
    void update();
    void draw();
    std::map<int, State*>& get_states();
private:
    std::map<int, State*> states;
    int state;
};

enum GameState
{
    MENU = 0,
    PLAYING = 1,
    PAUSED = 2
};
#endif //STATEMANAGER_HPP
