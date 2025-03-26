#ifndef TRANSFORMCOMPONENT_HPP
#define TRANSFORMCOMPONENT_HPP
#include "ECS.hpp"
#include "Vec2D.hpp"
#include "InputHandler.hpp"

class TransformComponent final : public Component
{
public:
    TransformComponent();
    TransformComponent(float x, float y);
    void init() override;
    void update() override;
    void draw() override;
    Vec2D& get_pos() const;
    float get_speed() const;
    void set_pos(float x, float y) const;
    void set_speed(float speed);
    InputHandler *get_input() const;
private:
    Vec2D* pos;
    float speed = 2.0f;
    InputHandler* input_handler{};
};

#endif //TRANSFORMCOMPONENT_HPP
