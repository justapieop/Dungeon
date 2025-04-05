#include "StatsUI.hpp"
#include "CurrentStatComponent.hpp"
#include "ECS.hpp"
#include "Game.hpp"
#include "Text.hpp"
#include "string"

StatsUI::StatsUI(const int x, const int y)
{
    this->hp_txt = new Text(x, y, 100, 50, "HP:");
    this->atk_txt = new Text(x, y + 50 + 10, 100, 50, "ATK:");
    this->def_txt = new Text(x, y + 100 + 20, 100, 50, "DEF:");

    this->hp_txt->create_text();
    this->atk_txt->create_text();
    this->def_txt->create_text();
<<<<<<< HEAD
=======

>>>>>>> 30860a8d356dfb457d2db61651154de0d7947c1a

    this->hp = this->atk = this->def = -1.0f;
}

StatsUI::~StatsUI() = default;

void StatsUI::set_stats(const float hp, const float atk, const float def)
{
    this->hp = hp;
    this->atk = atk;
    this->def = def;
<<<<<<< HEAD
    if (this->hp < 0.0f) this->hp = 0.0f;
=======
>>>>>>> 30860a8d356dfb457d2db61651154de0d7947c1a
    this->hp_txt->set_text("HP: " + std::to_string(this->hp));
    this->atk_txt->set_text("ATK: " + std::to_string(this->atk));
    this->def_txt->set_text("DEF: " + std::to_string(this->def));
}

void StatsUI::draw()
{
    this->hp_txt->draw();
    this->atk_txt->draw();
    this->def_txt->draw();
}
