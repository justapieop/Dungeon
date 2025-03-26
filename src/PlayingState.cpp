#include "PlayingState.hpp"
#include "ECS.hpp"
#include "SDL2/SDL.h"
#include "Game.hpp"
#include "StateManager.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include "CollisionComponent.hpp"
#include "InputHandler.hpp"

PlayingState::PlayingState()
{
    this->component_manager = new ComponentManager();
    this->player = &this->component_manager->add_entity();

    this->player->add_components<TransformComponent>(300, 300);
    this->player->add_components<SpriteComponent>("./assets/tiles/tile_0084.png");
    this->player->add_components<InputHandler>();
    this->player->add_components<CollisionComponent>();
}

PlayingState::~PlayingState() = default;

void PlayingState::update()
{
    switch (Game::event.type)
    {
        case SDL_KEYDOWN:
            if (Game::event.key.keysym.sym == SDLK_ESCAPE)
            {
                Game::state_manager->set_state(GameState::PAUSED);
            }
            break;
        default:
            break;
    }
    this->component_manager->update();
}

void PlayingState::draw()
{
    Game::map->draw();
    this->component_manager->draw();
}
