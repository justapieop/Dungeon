#include "CollisionComponent.hpp"
#include "Game.hpp"
#include "SpriteComponent.hpp"
#include "TransformComponent.hpp"
#include "Vec2D.hpp"
#include "memory"
#include "vector"

CollisionComponent::CollisionComponent() = default;

CollisionComponent::~CollisionComponent() = default;

void CollisionComponent::draw() {}

void CollisionComponent::init() {
    if (!this->entity->has_component<SpriteComponent>()) {
        this->entity->add_components<SpriteComponent>();
    }
    this->sprite_component = &this->entity->get_component<SpriteComponent>();
    if (!this->entity->has_component<TransformComponent>()) {
        this->entity->add_components<TransformComponent>();
    }
    this->transform_component =
        &this->entity->get_component<TransformComponent>();
    this->collision = Game::coll_map;

    this->hitboxes = std::vector<std::unique_ptr<SDL_FRect>>();
    for (int i = 0; i < this->collision->get_map().size(); i++) {
        for (int j = 0; j < this->collision->get_map()[i].size(); j++) {
            if (this->collision->get_map()[i][j] == 1) {
                std::unique_ptr<SDL_FRect> rect{new SDL_FRect()};
                rect->y = static_cast<float>(i) * 16.0f;
                rect->x = static_cast<float>(j) * 16.0f;
                rect->w = rect->h = 16.0f;
                this->hitboxes.push_back(std::move(rect));
            }
        }
    }
}

void CollisionComponent::update() {
    const Vec2D* movement =
        &this->transform_component->get_input().get_movement();
    Vec2D* pos = &this->transform_component->get_pos();
    const float dx = movement->get_x() * this->transform_component->get_speed();
    float dy = movement->get_y() * this->transform_component->get_speed();
    auto* future = new Vec2D(pos->get_x() + dx, pos->get_y() + dy);
    bool is_collided = false;
    this->sprite_component->get_rect().x += dx;
    this->sprite_component->get_rect().y += dy;

    for (const auto& box : this->hitboxes) {
        if (SDL_HasIntersectionF(&this->sprite_component->get_rect(),
                                 box.get())) {
            is_collided = true;
        }
    }
    if (!is_collided) {
        this->transform_component->set_pos(future->get_x(), future->get_y());
    }
}
