#include "PlayingState.hpp"
#include "CurrentStatComponent.hpp"
#include "ECS.hpp"
#include "EventHandler.hpp"
#include "SDL2/SDL.h"
#include "Game.hpp"
#include "EventHandler.hpp"
#include "SDL_keycode.h"
#include "SDL_mixer.h"
#include "SDL_rect.h"
#include "StateManager.hpp"
#include "StatsComponent.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include "CollisionComponent.hpp"
#include "InputHandler.hpp"

PlayingState::PlayingState()
{
    this->music = Mix_LoadMUS("./assets/audio/bg.mp3");
    Mix_PlayMusic(this->music, -1);
    this->component_manager = new ComponentManager();

    this->player = &this->component_manager->add_entity();
    this->player->add_components<TransformComponent>(300, 300);
    this->player->add_components<SpriteComponent>("./assets/tiles/tile_0084.png");
    this->player->add_components<InputHandler>();
    this->player->add_components<CollisionComponent>();
    this->player->add_components<StatsComponent>();
    this->player->add_components<CurrentStatComponent>();


    this->enemy = &this->component_manager->add_entity();
    this->enemy->add_components<TransformComponent>(300, 200);
    this->enemy->add_components<SpriteComponent>("./assets/tiles/tile_0100.png");
    this->enemy->add_components<StatsComponent>();
    this->enemy->add_components<CurrentStatComponent>();
}

PlayingState::~PlayingState()
{
    Mix_FreeMusic(this->music);
}

void PlayingState::update()
{

    switch (Game::event.type)
    {
        case SDL_KEYDOWN:
            if (Game::event.key.keysym.sym == SDLK_ESCAPE)
            {
                Game::state_manager->set_state(GameState::PAUSED);
            }
            if (Game::event.key.keysym.sym == SDLK_e)
            {
                int x, y;
                for (int i = -1; i < 2; i++)
                {
                    for (int j = -1; j < 2; j++)
                    {
                       x = this->player->get_component<SpriteComponent>().get_rect().x + 16 * j;
                       y =this->player->get_component<SpriteComponent>().get_rect().y + 16 * i;

                    }
                }
            }
            break;
        default:
            break;
    }
    this->component_manager->update();

    if (
        SDL_HasIntersectionF(
            &this->player->get_component<SpriteComponent>().get_rect(),
            &this->enemy->get_component<SpriteComponent>().get_rect()
        )
    )
    {
        EventHandler::trigger_event("enemy_encounter_event", player, enemy);
    }
}

void PlayingState::draw()
{
    Game::map->draw();
    this->component_manager->draw();
}
