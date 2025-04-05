#ifndef PAUSEDSTATE_HPP
#define PAUSEDSTATE_HPP
#include "State.hpp"
#include "Text.hpp"

class PausedState : public State
{
public:
    PausedState();
    ~PausedState() override;

    void update() override;
    void draw() override;
private:
    Text *title_txt, *exit_txt;
};
#endif //PAUSEDSTATE_HPP
