#ifndef GAMEOVERSTATE_HPP
#define GAMEOVERSTATE_HPP
#include "State.hpp"
#include "SDL2/SDL.h"

class GameOverState : public State
{
public:
    GameOverState();
    ~GameOverState() override;

    void update() override;
    void draw() override;
private:
    SDL_Surface *title_text{}, *exit_text{};
    SDL_Texture *title{}, *exit{};
    SDL_Rect *dest{}, *dest2{};
};

#endif //GAMEOVERSTATE_HPP
