#include "TextureManager.hpp"
#include "Game.hpp"
#include "SDL_image.h"
#include "SDL.h"
#include "SDL_render.h"
#include "string"

SDL_Texture* TextureManager::load_texture(const std::string& path)
{
    SDL_Surface* surface = IMG_Load(path.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);

    SDL_FreeSurface(surface);
    return texture;
}

void TextureManager::draw_f(SDL_Texture* texture, const SDL_Rect src, const SDL_FRect dest)
{
    SDL_RenderCopyF(Game::renderer, texture, &src, &dest);
}

void TextureManager::draw(SDL_Texture* texture, const SDL_Rect src, const SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}
