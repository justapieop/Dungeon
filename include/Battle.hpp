#ifndef BATTLE_HPP
#define BATTLE_HPP
#include "ECS.hpp"

enum BattleWinner
{
    PLAYER = 0,
    ENEMY = 1,
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
    float heal();
    void flee();

    Entity& get_player();
    Entity& get_enemy();
private:
    bool turn;
    Entity *player{}, *enemy{};
};
#endif
