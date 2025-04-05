#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP
#include "State.hpp"
#include "Text.hpp"

class MenuState : public State
{
public:
    MenuState();
    ~MenuState() override;

    void update() override;
    void draw() override;
private:
    Text *title_txt, *exit_txt;
};

#endif //MENUSTATE_HPP
