#include "EnemyEncounterEvent.hpp"
#include "ECS.hpp"
#include "Game.hpp"
#include "StateManager.hpp"
#include "utility"

EnemyEncounterEvent::EnemyEncounterEvent() = default;

EnemyEncounterEvent::~EnemyEncounterEvent() = default;

void EnemyEncounterEvent::execute()
{
    Entity *player = std::any_cast<Entity*>(this->get_event_args().get_args()[0]);
    Entity *enemy = std::any_cast<Entity*>(this->get_event_args().get_args()[1]);

    Game::state_manager->set_state(GameState::FIGHTING, player, enemy);
}
