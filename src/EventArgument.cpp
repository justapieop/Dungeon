#include "EventArgument.hpp"
#include "vector"
#include "any"

EventArgument::EventArgument()
{
    this->args = std::vector<std::any>();
}

EventArgument::~EventArgument() = default;

std::vector<std::any>& EventArgument::get_args()
{
    return this->args;
}
