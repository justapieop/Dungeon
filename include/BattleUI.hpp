#ifndef BATTLEUI_HPP
#define BATTLEUI_HPP
#include "Battle.hpp"
#include "ECS.hpp"
#include "SDL2/SDL.h"
#include "Selection.hpp"
#include "StatsUI.hpp"
#include "vector"

class BattleUI
{
public:
    BattleUI(Battle& battle);
    ~BattleUI();

    void update();
    void draw();
    std::vector<Selection*>& get_sel();
    int get_current() const;
    void set_current(const int current);

    Battle& get_battle();
private:
    std::vector<Selection*> sel;
    Battle *battle;
    StatsUI *player, *enemy;
    int current;
    Text *action;
};
#endif //BATTLEUI_HPP
