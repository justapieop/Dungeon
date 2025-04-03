#include "GameOverState.hpp"
#include "Game.hpp"
#include "SDL2/SDL.h"
#include "StateManager.hpp"

GameOverState::GameOverState() = default;

GameOverState::~GameOverState() = default;

void GameOverState::update()
{
    const Uint8 *key_states = SDL_GetKeyboardState(nullptr);

    if (key_states[SDL_SCANCODE_SPACE])
    {
        Game::state_manager->set_state(GameState::MENU);
    }

    if (key_states[SDL_SCANCODE_ESCAPE])
    {
        Game::force_stop();
    }
}

void GameOverState::draw()
{
    this->title_text = TTF_RenderText_Blended(Game::font, "Press SPACEBAR to quit", { 255, 255, 255, SDL_ALPHA_OPAQUE });
    this->title = SDL_CreateTextureFromSurface(Game::renderer, this->title_text);
    this->exit_text = TTF_RenderText_Blended(Game::font, "Press ESC to return to menu", { 255, 255, 255, SDL_ALPHA_OPAQUE });
    this->exit = SDL_CreateTextureFromSurface(Game::renderer, this->exit_text);
    this->dest = new SDL_Rect(256, 128, 256, 16);
    this->dest2 = new SDL_Rect(256, 256, 244, 16);
    SDL_RenderCopy(Game::renderer, this->title, nullptr, this->dest);
    SDL_RenderCopy(Game::renderer, this->exit, nullptr, this->dest2);
    SDL_FreeSurface(this->title_text);
    SDL_FreeSurface(this->exit_text);
    SDL_DestroyTexture(this->title);
    SDL_DestroyTexture(this->exit);
}
