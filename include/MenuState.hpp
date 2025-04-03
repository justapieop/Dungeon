#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP
#include "State.hpp"
#include "SDL2/SDL.h"

class MenuState : public State
{
public:
    MenuState();
    ~MenuState() override;

    void update() override;
    void draw() override;
private:
    SDL_Surface *title_text, *exit_text;
    SDL_Texture *title, *exit;
    SDL_Rect *dest, *dest2;
};

#endif //MENUSTATE_HPP
