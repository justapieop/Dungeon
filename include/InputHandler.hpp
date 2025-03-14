//
// Created by JustAPie on 14/03/2025.
//

#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP
#include "ECS.hpp"
#include "TransformComponent.hpp"

class InputHandler : public Component
{
public:
    InputHandler();
    ~InputHandler() override;

    void init() override;
    void update() override;
    void draw() override;
private:
    TransformComponent *transform_component{};
};

#endif //INPUTHANDLER_HPP
