#include "Event.hpp"
#include "EventArgument.hpp"

Event::Event()
{
    this->args = new EventArgument();
}

Event::~Event() = default;

EventArgument& Event::get_event_args() const
{
    return *this->args;
}
