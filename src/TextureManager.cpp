//
// Created by JustAPie on 2/8/2025.
//

#include "TextureManager.hpp"
#include "Game.hpp"
#include "SDL_image.h"
#include "SDL.h"
#include "string"

SDL_Texture *TextureManager::load_texture(const std::string& path) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);

    SDL_FreeSurface(surface);
    return texture;
}
