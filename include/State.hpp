#ifndef STATE_HPP
#define STATE_HPP
#include "vector"
#include "any"

class State
{
public:
    State();
    virtual ~State();
    virtual void update() = 0;
    virtual void draw() = 0;

    std::vector<std::any>& get_args();
private:
    std::vector<std::any> args;
};
#endif //STATE_HPP
