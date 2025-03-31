#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP
#include "Event.hpp"
#include "string"
#include "map"
#include "utility"

class EventHandler
{
public:
    static void init();

    template <typename T>
    inline static void add_event(const std::string& event_name)
    {
        if (!events.count(event_name))
        {
            events[event_name] = new T();
        }
    }

    template <typename... TArgs>
    inline static void trigger_event(const std::string& event_name, TArgs&&... args)
    {
        if (events.count(event_name))
        {
            events[event_name]->get_event_args().get_args().clear();
            (events[event_name]->get_event_args().get_args().push_back(std::forward<TArgs>(args)), ...);
            events[event_name]->execute();
        }
    }
private:
    static std::map<std::string, Event*> events;
};
#endif //EVENTHANDLER_HPP
