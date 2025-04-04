#ifndef STATSUI_HPP
#define STATSUI_HPP
#include "ECS.hpp"
#include "SDL2/SDL.h"

class StatsUI
{
public:
    StatsUI(const int x, const int y);
    ~StatsUI();

    void set_stats(const float hp, const float atk, const float def);

    void draw();
private:
    SDL_Rect *hp_src, *hp_dest, *atk_src, *atk_dest, *def_src, *def_dest;
    SDL_Texture *hp_texture, *atk_texture, *def_texture;
    SDL_Surface *hp_surface, *atk_surface, *def_surface;
    float hp, atk, def;
};
#endif //STATSUI_HPP
