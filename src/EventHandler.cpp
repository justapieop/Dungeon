#include "EventHandler.hpp"
#include "Event.hpp"
#include "string"
#include "EnemyEncounterEvent.hpp"

std::map<std::string, Event*> EventHandler::events;

void EventHandler::init()
{
    events = std::map<std::string, Event*>();
    add_event<EnemyEncounterEvent>("enemy_encounter_event");
}
