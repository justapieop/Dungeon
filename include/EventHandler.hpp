#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP
#include "Event.hpp"
#include "string"
#include "map"

class EventHandler
{
public:
    static void init();

    template <typename T, typename... TArgs>
    static void add_event(std::string event_name, TArgs... args);

    template <typename T, typename... TArgs>
    static void trigger_event(std::string event_name, TArgs... args);
private:
    static std::map<std::string, Event*> events;
};
#endif //EVENTHANDLER_HPP
