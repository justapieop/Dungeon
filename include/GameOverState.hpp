#ifndef GAMEOVERSTATE_HPP
#define GAMEOVERSTATE_HPP
#include "State.hpp"
#include "Text.hpp"

class GameOverState : public State
{
public:
    GameOverState();
    ~GameOverState() override;

    void update() override;
    void draw() override;
private:
    Text *header, *exit;
};

#endif //GAMEOVERSTATE_HPP
