//
// Created by JustAPie on 2/8/2025.
//

#include "TextureManager.hpp"

#include <SDL_image.h>
#include <SDL2/SDL.h>

SDL_Texture *TextureManager::load_texture(const char *path, SDL_Renderer *renderer) {
    SDL_Surface* surface = IMG_Load(path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);
    return texture;
}
