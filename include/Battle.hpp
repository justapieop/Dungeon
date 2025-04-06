#ifndef BATTLE_HPP
#define BATTLE_HPP
#include "ECS.hpp"

enum BattleWinner
{
    ON_GOING = 0,
    PLAYER = 1,
    ENEMY = 2,
};

class Battle
{
public:
    Battle();
    ~Battle();

    void set_entities(Entity& player, Entity& enemy);
    bool get_turn() const;
    void set_turn(bool turn);

    BattleWinner determine() const;
    float attack(bool invaded = false) const;
    float heal() const;
    void flee();

    Entity& get_player() const;
    Entity& get_enemy() const;
private:
    bool turn;
    Entity *player{}, *enemy{};
};
#endif
