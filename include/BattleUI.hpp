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
    void draw() const;
    std::vector<Selection*>& get_sel();
    int get_current() const;
    void set_current(int current);
    void trigger() const;
    void enemy_act() const;
    Battle& get_battle() const;
private:
    std::vector<Selection*> sel;
    Battle *battle;
    StatsUI *player, *enemy;
    int current;
    bool confirm;
    Text *action;
};
#endif //BATTLEUI_HPP
