#include "BattleUI.hpp"
#include "Action.hpp"
#include "Battle.hpp"
#include "CurrentStatComponent.hpp"
#include "Game.hpp"
#include "Selection.hpp"
#include "StatsUI.hpp"
#include "TextureManager.hpp"
#include "Utils.hpp"
#include "vector"
#include "SpriteComponent.hpp"

BattleUI::BattleUI(Battle& battle) : action(nullptr) {
    this->battle = &battle;
    this->current = 0;
    this->sel = std::vector<Selection*>();

    this->sel.push_back(new Selection(30, 350, "Attack"));
    this->sel.back()->set_action(ATTACK);

    this->sel.push_back(new Selection(200, 350, "Heal"));
    this->sel.back()->set_action(HEAL);

    this->sel.push_back(new Selection(380, 350, "Flee"));
    this->sel.back()->set_action(FLEE);

    this->sel.push_back(new Selection(560, 350, "Skip"));
    this->sel.back()->set_action(SKIP);

    this->player = new StatsUI(30, 100);
    this->enemy = new StatsUI(600, 100);

    this->action = new Text(30, 300, 240, 30, "");
    this->action->create_text();

    this->turn_txt = new Text(300, 50, 150, 20, "");
    this->turn_txt->create_text();

    this->enemy_src = new SDL_Rect(0, 0, 16, 16);
    this->enemy_dest = new SDL_Rect(300, 120, 128, 128);

    this->enemy_texture = nullptr;

    this->confirm = true;
}

BattleUI::~BattleUI() = default;

int BattleUI::get_current() const { return this->current; }

void BattleUI::set_current(const int current) { this->current = current; }

std::vector<Selection*>& BattleUI::get_sel() { return this->sel; }

void BattleUI::update() {
    if (this->get_battle().get_turn()) this->turn_txt->set_text("Your turn");
    else this->turn_txt->set_text("Enemy turn");

    if (&this->get_texture() == nullptr) {
        this->set_texture(this->get_battle().get_enemy().get_component<SpriteComponent>().get_path());
    }
    
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
                    this->set_confirm(true);
                    if (!this->get_battle().get_turn()) {
                        this->enemy_act();
                    }
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


void BattleUI::trigger() {
    if (!this->get_battle().get_turn()) return;
    switch (const Selection* active = this->sel[this->get_current()];
            active->get_action()) {
            case ATTACK: {
                const float dmg = this->get_battle().attack();
                this->action->set_text("You dealt " + Utils::round_float(dmg) + " DMG");
                break;
            }
            case HEAL: {
                const float heal_hp = this->get_battle().heal();
                this->action->set_text("You recovered " + Utils::round_float(heal_hp) + " HP");
                break;
            }
            case FLEE: {
                Game::state_manager->set_state(PLAYING);
                return;
            }
            case SKIP: {
                this->action->set_text("You skipped your turn");
                break;
            }
            default:
                break;
            }
    this->get_battle().set_turn(false);
    this->set_confirm(false);
}

void BattleUI::enemy_act() const {
    if (this->get_battle().get_turn()) return;
    const float dmg = this->get_battle().attack(true);
    this->action->set_text("Enemy dealt " + Utils::round_float(dmg) + " DMG");
    this->get_battle().set_turn(true);
}

void BattleUI::draw() const {
    this->player->draw();
    this->enemy->draw();
    for (const auto & i : this->sel) {
        i->draw();
    }
    if (!this->action->get_text().empty())
        this->action->draw();
    this->turn_txt->draw();
    TextureManager::draw(
        this->enemy_texture,
        *this->enemy_src,
        *this->enemy_dest
    );
}

Battle& BattleUI::get_battle() const { return *this->battle; }

bool BattleUI::get_confirm() const {
    return this->confirm;
}

void BattleUI::set_confirm(const bool confirm) {
    this->confirm = confirm;
}

SDL_Texture& BattleUI::get_texture() const {
    return *this->enemy_texture;
}

void BattleUI::set_texture(const std::string& path) {
    this->enemy_texture = TextureManager::load_texture(path);
}

