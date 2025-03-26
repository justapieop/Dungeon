#ifndef PAUSEDSTATE_HPP
#define PAUSEDSTATE_HPP
#include "SDL2/SDL.h"
#include "State.hpp"

class PausedState : public State
{
public:
    PausedState();
    ~PausedState() override;

    void update() override;
    void draw() override;
private:
    SDL_Surface *title_text, *exit_text;
    SDL_Texture *title, *exit;
    SDL_Rect *dest, *dest2;
};
#endif //PAUSEDSTATE_HPP
