#ifndef VICTORYSTATE_HPP
#define VICTORYSTATE_HPP
#include "State.hpp"
#include "Text.hpp"

class VictoryState : public State {
public:
    VictoryState();
    ~VictoryState() override;

    void update() override;
    void draw() override;
private:
    Text *title, *exit;
};

#endif //VICTORYSTATE_HPP
