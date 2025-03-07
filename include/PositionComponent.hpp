//
// Created by JustAPie on 06/03/2025.
//

#ifndef POSITIONCOMPONENT_HPP
#define POSITIONCOMPONENT_HPP
#include "ECS.hpp"

class PositionComponent final : public Component
{
public:
    PositionComponent(int x, int y);
    void init() override;
    void update() override;
    void draw() override;
    [[nodiscard]] int get_x() const;
    [[nodiscard]] int get_y() const;

    void set_pos(int x, int y);

private:
    int x{}, y{};
};

#endif //POSITIONCOMPONENT_HPP
