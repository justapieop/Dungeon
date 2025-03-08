//
// Created by JustAPie on 07/03/2025.
//

#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include "SDL2/SDL.h"
#include "string"
#include "TransformComponent.hpp"

class SpriteComponent final : public Component
{
public:
    SpriteComponent();
    explicit SpriteComponent(const std::string& path);

    void update() override;
    void draw() override;
    void init() override;
    void set_texture(SDL_Texture *texture);

private:
    TransformComponent *transform{};
    SDL_Texture *texture{};
    SDL_Rect src{}, dest{};
};

#endif //SPRITECOMPONENT_HPP
