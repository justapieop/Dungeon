#ifndef STATE_HPP
#define STATE_HPP

class State
{
public:
    State();
    virtual ~State();
    virtual void update() = 0;
    virtual void draw() = 0;
};
#endif //STATE_HPP
