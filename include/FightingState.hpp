#ifndef FIGHTINGSTATE_HPP
#define FIGHTINGSTATE_HPP
#include "BattleUI.hpp"
#include "ECS.hpp"
#include "State.hpp"
#include "string"

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
    std::string status_text;
    BattleUI *ui;
};
#endif //FIGHTINGSTATE_HPP
