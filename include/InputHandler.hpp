#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP
#include "ECS.hpp"
#include "Vec2D.hpp"

class InputHandler : public Component
{
public:
    InputHandler();
    ~InputHandler() override;

    void init() override;
    void update() override;
    void draw() override;

    Vec2D& get_movement() const;
private:
    Vec2D *movement;
};

#endif //INPUTHANDLER_HPP
