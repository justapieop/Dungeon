//
// Created by JustAPie on 07/03/2025.
//

#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include "PositionComponent.hpp"
#include "SDL2/SDL.h"
#include "string"

class SpriteComponent final : public Component
{
public:
    SpriteComponent();
    explicit SpriteComponent(const std::string& path);

    void update() override;
    void draw() override;
    void init() override;

private:
    PositionComponent *position_component{};
    SDL_Texture *texture{};
    SDL_Rect src{}, dest{};
};

#endif //SPRITECOMPONENT_HPP
