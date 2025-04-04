#ifndef BATTLEUI_HPP
#define BATTLEUI_HPP
#include "ECS.hpp"
#include "SDL2/SDL.h"
#include "SDL_rect.h"

class BattleUI
{
public:
    BattleUI();
    ~BattleUI();

    void update(const Entity& player, const Entity& enemy);
    void draw();
private:
    SDL_Rect *attack, *attack_dest, *heal, *heal_dest;
    SDL_Texture *button;
};
#endif //BATTLEUI_HPP
