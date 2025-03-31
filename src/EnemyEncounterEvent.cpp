#include "EnemyEncounterEvent.hpp"
#include "CurrentStatComponent.hpp"
#include "ECS.hpp"
#include "SDL2/SDL.h"
#include "SDL_log.h"
#include "utility"
#include <any>

EnemyEncounterEvent::EnemyEncounterEvent() = default;

EnemyEncounterEvent::~EnemyEncounterEvent() = default;

void EnemyEncounterEvent::execute()
{
    Entity *player = std::any_cast<Entity*>(this->get_event_args().get_args()[0]);
    SDL_Log("%d", player->get_component<CurrentStatComponent>().get_hp());
}
