#ifndef ENEMYENCOUNTEREVENT_HPP
#define ENEMYENCOUNTEREVENT_HPP
#include "Event.hpp"
#include "utility"
#include "ECS.hpp"
#include "vector"

class EnemyEncounterEvent : public Event
{
public:
    EnemyEncounterEvent();
    ~EnemyEncounterEvent() override;

    void execute() override;
};
#endif //ENEMYENCOUNTEREVENT_HPP
