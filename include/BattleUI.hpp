#ifndef BATTLEUI_HPP
#define BATTLEUI_HPP
#include "Battle.hpp"
#include "Selection.hpp"
#include "StatsUI.hpp"
#include "vector"
#include "SDL2/SDL.h"

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
    void trigger();
    void enemy_act() const;
    Battle& get_battle() const;
    bool get_confirm() const;
    void set_confirm(bool confirm);
    SDL_Texture& get_texture() const;
    void set_texture(const std::string& path);
private:
    std::vector<Selection*> sel;
    Battle *battle;
    StatsUI *player, *enemy;
    int current;
    bool confirm;
    Text *action, *turn_txt;
    SDL_Rect *enemy_src, *enemy_dest;
    SDL_Texture *enemy_texture;
};
#endif //BATTLEUI_HPP
