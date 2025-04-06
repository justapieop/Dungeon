#include "StatsUI.hpp"
#include "ECS.hpp"
#include "Game.hpp"
#include "Text.hpp"
#include "Utils.hpp"

StatsUI::StatsUI(const int x, const int y) {
    this->hp_txt = new Text(x, y, 110, 25, "HP:");
    this->atk_txt = new Text(x, y + 25 + 10, 110, 25, "ATK:");
    this->def_txt = new Text(x, y + 50 + 20, 110, 25, "DEF:");

    this->hp_txt->create_text();
    this->atk_txt->create_text();
    this->def_txt->create_text();

    this->hp = this->atk = this->def = -1.0f;
}

StatsUI::~StatsUI() = default;

void StatsUI::set_stats(const float hp, const float atk, const float def) {
    this->hp = hp;
    this->atk = atk;
    this->def = def;
    if (this->hp < 0.0f)
        this->hp = 0.0f;
    this->hp_txt->set_text("HP: " + Utils::round_float(this->hp));
    this->atk_txt->set_text("ATK: " + Utils::round_float(this->hp));
    this->def_txt->set_text("DEF: " + Utils::round_float(this->hp));
}

void StatsUI::draw() const {
    this->hp_txt->draw();
    this->atk_txt->draw();
    this->def_txt->draw();
}
