#ifndef STATSUI_HPP
#define STATSUI_HPP
#include "Text.hpp"

class StatsUI
{
public:
    StatsUI(int x, int y);
    ~StatsUI();

    void set_stats(float hp, float atk, float def);

    void draw() const;
private:
    Text *hp_txt, *atk_txt, *def_txt;
    float hp, atk, def;
};
#endif //STATSUI_HPP
