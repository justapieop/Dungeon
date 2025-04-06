#include "BattleUI.hpp"
#include "Action.hpp"
#include "Battle.hpp"
#include "Selection.hpp"
#include "StatsUI.hpp"
#include "vector"
#include "CurrentStatComponent.hpp"
#include "Game.hpp"
#include "Utils.hpp"

BattleUI::BattleUI(Battle& battle) : action(nullptr) {
    this->battle = &battle;
    this->current = 0;
    this->sel = std::vector<Selection*>();

    this->sel.push_back(new Selection(30, 350, "Attack"));
    this->sel.back()->set_action(ATTACK);

    this->sel.push_back(new Selection(250, 350, "Heal"));
    this->sel.back()->set_action(HEAL);

    this->sel.push_back(new Selection(480, 350, "Flee"));
    this->sel.back()->set_action(FLEE);

    this->player = new StatsUI(30, 100);
    this->enemy = new StatsUI(600, 100);

    this->action = new Text(30, 300, 240, 30, "");
    this->action->create_text();

    this->confirm = true;
}

BattleUI::~BattleUI() = default;

int BattleUI::get_current() const { return this->current; }

void BattleUI::set_current(const int current) { this->current = current; }

std::vector<Selection*>& BattleUI::get_sel() { return this->sel; }

void BattleUI::update() {
    const CurrentStatComponent* current_player =
        &this->get_battle().get_player().get_component<CurrentStatComponent>();
    const CurrentStatComponent *current_enemy = &this->get_battle().get_enemy().get_component<CurrentStatComponent>();

    this->player->set_stats(current_player->get_hp(), current_player->get_atk(), current_player->get_def());
    this->enemy->set_stats(current_enemy->get_hp(), current_enemy->get_atk(), current_enemy->get_def());

    if (Game::event.type == SDL_KEYDOWN) {
        switch (Game::event.key.keysym.sym) {
            case SDLK_LEFT:
                --this->current;
                break;
            case SDLK_RIGHT:
                ++this->current;
                break;
            case SDLK_SPACE: {
                this->trigger();
                break;
            }
            case SDLK_RETURN: {
                if (!this->confirm) {
                    this->action->set_text("");
                    this->confirm = true;
                }
                break;
            }
            default:
                break;
        }
    }

    if (this->get_current() >= this->sel.size()) this->current = this->sel.size() - 1;
    if (this->get_current() <= 0) this->current = 0;

    for (int i = 0; i < this->sel.size(); i++) {
        this->sel[i]->set_active(false);
        if (i == this->current) this->sel[i]->set_active(true);
    }
}


void BattleUI::trigger() const {
    if (!this->battle->get_turn()) return;
    SDL_Log("player run");
    switch (const Selection* active = this->sel[this->get_current()];
            active->get_action()) {
            case ATTACK: {
                const float dmg = this->battle->attack();
                this->action->set_text("You dealt " + Utils::round_float(-dmg) + " DMG");
                break;
            }
            case HEAL: {
                const float heal_hp = this->battle->heal();
                this->action->set_text("You recovered " + Utils::round_float(heal_hp) + " HP");
                break;
            }
            case FLEE: {
                return;
            }
            default:
                break;
            }
    this->battle->set_turn(false);
}

void BattleUI::enemy_act() const {
    if (this->battle->get_turn()) return;
    SDL_Log("enemy run");
    const float dmg = this->battle->attack(true);
    this->action->set_text("Enemy dealt " + std::to_string(dmg) + " DMG");
    this->battle->set_turn(true);
}

void BattleUI::draw() const {
    this->player->draw();
    this->enemy->draw();
    for (const auto & i : this->sel) {
        i->draw();
    }
    if (!this->action->get_text().empty())
        this->action->draw();
}

Battle& BattleUI::get_battle() const { return *this->battle; }
