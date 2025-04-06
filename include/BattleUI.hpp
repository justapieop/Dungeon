#ifndef BATTLEUI_HPP
#define BATTLEUI_HPP
#include "Battle.hpp"
#include "Selection.hpp"
#include "StatsUI.hpp"
#include "vector"

class BattleUI
{
public:
    explicit BattleUI(Battle& battle);
    ~BattleUI();

    void update();
    void draw();
    std::vector<Selection*>& get_sel();
    int get_current() const;
    void set_current(int current);
    void trigger();
    void enemy_act();
    Battle& get_battle();
private:
    std::vector<Selection*> sel;
    Battle *battle;
    StatsUI *player, *enemy;
    int current;
    bool confirm;
    Text *action;
};
#endif //BATTLEUI_HPP
