#ifndef FIGHTINGSTATE_HPP
#define FIGHTINGSTATE_HPP
#include "ECS.hpp"
#include "State.hpp"
class FightingState : public State
{
public:
    FightingState();
    ~FightingState() override;

    void update() override;
    void draw() override;

    void set_my_turn(bool is_my_turn);
    bool my_turn() const;
private:
    bool is_my_turn;
    Entity *player{}, *enemy{};
};
#endif //FIGHTINGSTATE_HPP
