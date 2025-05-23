#ifndef COLLISIONCOMPONENT_HPP
#define COLLISIONCOMPONENT_HPP
#include "ECS.hpp"
#include "Map.hpp"
#include "SDL_rect.h"
#include "SpriteComponent.hpp"
#include "TransformComponent.hpp"
#include "SDL2/SDL.h"
#include "vector"
#include "memory"

class CollisionComponent : public Component
{
public:
    CollisionComponent();
    ~CollisionComponent() override;

    void update() override;
    void draw() override;
    void init() override;
private:
    SpriteComponent* sprite_component{};
    TransformComponent* transform_component{};
    Map *collision{};
    std::vector<std::unique_ptr<SDL_FRect>> hitboxes;
};

#endif //COLLISIONCOMPONENT_HPP
