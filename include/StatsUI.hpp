#ifndef STATSUI_HPP
#define STATSUI_HPP
#include "ECS.hpp"
#include "SDL2/SDL.h"
#include "Text.hpp"

class StatsUI
{
public:
    StatsUI(const int x, const int y);
    ~StatsUI();

    void set_stats(const float hp, const float atk, const float def);

    void draw();
private:
    Text *hp_txt, *atk_txt, *def_txt;
    float hp, atk, def;
};
#endif //STATSUI_HPP
