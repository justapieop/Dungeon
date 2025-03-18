//
// Created by JustAPie on 14/03/2025.
//

#ifndef COLLISIONCOMPONENT_HPP
#define COLLISIONCOMPONENT_HPP
#include <SDL_rect.h>

#include "ECS.hpp"
#include "TransformComponent.hpp"

class CollisionComponent : public Component
{
public:
    CollisionComponent();
    ~CollisionComponent() override;

    void update() override;
    void draw() override;
    void init() override;

   // [[nodiscard]] static bool check_collision(SDL_rect) const;
private:
    TransformComponent *transform_component{};
    SDL_Rect collider{};
};

#endif //COLLISIONCOMPONENT_HPP
