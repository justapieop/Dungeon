#include "EventHandler.hpp"
#include "string"

std::map<std::string, Event*> EventHandler::events;

void EventHandler::init()
{
    events = std::map<std::string, Event*>();
}

template <typename T>
void EventHandler::add_event(std::string event_name)
{
    if (!events.count(event_name))
    {
        events[event_name] = new T();
    }
}

template <typename T, typename... TArgs>
void EventHandler::trigger_event(std::string event_name, TArgs... args)
{
    if (events.count(event_name))
    {
        events[event_name]->execute(args...);
    }
}
