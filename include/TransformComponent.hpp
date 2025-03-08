//
// Created by JustAPie on 07/03/2025.
//

#ifndef TRANSFORMCOMPONENT_HPP
#define TRANSFORMCOMPONENT_HPP
#include "ECS.hpp"
#include "Vec2D.hpp"

class TransformComponent final : public Component
{
public:
    TransformComponent();
    TransformComponent(float x, float y);
    void init() override;
    void update() override;
    void draw() override;
    [[nodiscard]] Vec2D* get_pos() const;
    void set_pos(float x, float y) const;

private:
    Vec2D *pos;
};

#endif //TRANSFORMCOMPONENT_HPP
