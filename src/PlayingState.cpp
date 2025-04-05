#include "PlayingState.hpp"
#include "CollisionComponent.hpp"
#include "CurrentStatComponent.hpp"
#include "ECS.hpp"
#include "Game.hpp"
#include "InputHandler.hpp"
#include "SDL2/SDL.h"
#include "SpriteComponent.hpp"
#include "StateManager.hpp"
#include "StatsComponent.hpp"
#include "TransformComponent.hpp"

PlayingState::PlayingState() {
    this->music = Mix_LoadMUS("./assets/audio/bg.mp3");
    Mix_PlayMusic(this->music, -1);
    this->component_manager = new ComponentManager();

    this->player = &this->component_manager->add_entity();
    this->player->add_components<TransformComponent>(300, 300);
    this->player->add_components<SpriteComponent>(
        "./assets/tiles/tile_0084.png");
    this->player->add_components<InputHandler>();
    this->player->add_components<CollisionComponent>();
    this->player->add_components<StatsComponent>();
    this->player->add_components<CurrentStatComponent>();

    this->enemy = &this->component_manager->add_entity();
    this->enemy->add_components<TransformComponent>(300, 200);
    this->enemy->add_components<SpriteComponent>(
        "./assets/tiles/tile_0100.png");
    this->enemy->add_components<StatsComponent>();
    this->enemy->add_components<CurrentStatComponent>();
}

PlayingState::~PlayingState() { Mix_FreeMusic(this->music); }

void PlayingState::update() {
    this->component_manager->update();

    if (SDL_HasIntersectionF(
            &this->player->get_component<SpriteComponent>().get_rect(),
            &this->enemy->get_component<SpriteComponent>().get_rect())) {
        Game::state_manager->set_state(GameState::FIGHTING, player, enemy);
        return;
    }

    if (Game::event.type != SDL_KEYDOWN)
        return;
    if (Game::event.key.keysym.sym == SDLK_ESCAPE) {
        Game::state_manager->set_state(GameState::PAUSED);
    }
}

void PlayingState::draw() {
    Game::map->draw();
    this->component_manager->draw();
}
