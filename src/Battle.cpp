#include "Battle.hpp"
#include "Constants.hpp"
#include "CurrentStatComponent.hpp"
#include "ECS.hpp"

Battle::Battle() { this->turn = true; }

void Battle::set_entities(Entity& player, Entity& enemy) {
    this->player = &player;
    this->enemy = &enemy;
}

Battle::~Battle() = default;

float Battle::attack(const bool invaded) const {
    CurrentStatComponent* player_current =
        &this->player->get_component<CurrentStatComponent>();
    CurrentStatComponent* enemy_current =
        &this->enemy->get_component<CurrentStatComponent>();

    float dmg = BASE_DAMAGE + (1.36 * player_current->get_atk() -
                               1.2 * enemy_current->get_def());
    if (!invaded) {
        if (this->turn)
            enemy_current->set_hp(enemy_current->get_hp() - dmg);
        else
            dmg = 0;
        return dmg;
    }

    dmg = BASE_DAMAGE +
          (1.36 * enemy_current->get_atk() - 1.22 * player_current->get_def());

    player_current->set_hp(player_current->get_hp() - dmg);
    return dmg;
}

float Battle::heal() {
    if (!this->turn)
        return 0.0f;
    CurrentStatComponent* player_current =
        &this->player->get_component<CurrentStatComponent>();
    player_current->set_hp(player_current->get_hp() + 5.0f);
    return 5.0f;
}

bool Battle::get_turn() const { return this->turn; }

void Battle::set_turn(const bool turn) { this->turn = turn; }

BattleWinner Battle::determine() const {
    CurrentStatComponent* player_current =
        &this->player->get_component<CurrentStatComponent>();
    CurrentStatComponent* enemy_current =
        &this->enemy->get_component<CurrentStatComponent>();

    if (enemy_current->get_hp() == 0.0f)
        return BattleWinner::PLAYER;
    return BattleWinner::ENEMY;
}

Entity& Battle::get_player() { return *this->player; }
Entity& Battle::get_enemy() { return *this->enemy; }
