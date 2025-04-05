#ifndef BATTLEUI_HPP
#define BATTLEUI_HPP
#include "Action.hpp"
#include "ECS.hpp"
#include "SDL2/SDL.h"
#include "Selection.hpp"
#include "StatsUI.hpp"
#include "vector"

class BattleUI
{
public:
    BattleUI();
    ~BattleUI();

    void update(Entity& player, Entity& enemy);
    void draw();
    std::vector<Selection*>& get_sel();
    int get_current() const;
    void set_current(int current);
    void trigger_action(Entity& entity, const Action action);
private:
    std::vector<Selection*> sel;
    StatsUI *player, *enemy;
    int current;
};
#endif //BATTLEUI_HPP
