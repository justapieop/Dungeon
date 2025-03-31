#ifndef EVENTARGUMENT_HPP
#define EVENTARGUMENT_HPP
#include "any"
#include "vector"
#include <vector>

class EventArgument
{
public:
    EventArgument();
    ~EventArgument();

    std::vector<std::any>& get_args();
private:
    std::vector<std::any> args;
};

#endif //EVENTARGUMENT_HPP
