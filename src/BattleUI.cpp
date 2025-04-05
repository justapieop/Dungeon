#include "BattleUI.hpp"
#include "Action.hpp"
#include "Battle.hpp"
#include "Selection.hpp"
#include "StatsUI.hpp"
#include "vector"

BattleUI::BattleUI(Battle& battle) {
    this->battle = &battle;
    this->current = 0;
    this->sel = std::vector<Selection*>();

    this->sel.push_back(new Selection(30, 350, "Attack"));
    this->sel.back()->set_action(Action::ATTACK);

    this->sel.push_back(new Selection(250, 350, "Heal"));
    this->sel.back()->set_action(Action::HEAL);

    this->sel.push_back(new Selection(480, 350, "Flee"));
    this->sel.back()->set_action(Action::FLEE);

    this->player = new StatsUI(30, 100);
    this->enemy = new StatsUI(500, 100);
}

BattleUI::~BattleUI() = default;

int BattleUI::get_current() const { return this->current; }

void BattleUI::set_current(const int current) { this->current = current; }

std::vector<Selection*>& BattleUI::get_sel() { return this->sel; }

void BattleUI::update() {}

void BattleUI::draw() {
    this->player->draw();
    this->enemy->draw();
    for (int i = 0; i < this->sel.size(); i++) {
        this->sel[i]->draw();
    }
}

Battle& BattleUI::get_battle() { return *this->battle; }
