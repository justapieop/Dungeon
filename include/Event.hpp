#ifndef EVENT_HPP
#define EVENT_HPP

#include "EventArgument.hpp"
class Event
{
public:
    Event();
    virtual ~Event();

    virtual void execute() = 0;
    EventArgument& get_event_args() const;
private:
    EventArgument *args;
};
#endif //EVENT_HPP
