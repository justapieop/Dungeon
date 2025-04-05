#include "Text.hpp"
#include "TextureManager.hpp"
#include "string"
#include "SDL2/SDL.h"
#include "Game.hpp"

Text::Text(const int x, const int y, const int w, const int h, const std::string& text)
{
    this->text = text;
    this->txt_src = new SDL_Rect(0, 0, w, h);
    this->txt_dest = new SDL_Rect(x, y, w, h);
}

Text::~Text() = default;

void Text::create_text()
{
    this->txt_surface = TTF_RenderText_Blended(Game::font, this->text.c_str(), { 255, 255, 255, SDL_ALPHA_OPAQUE });

    this->txt_texture = SDL_CreateTextureFromSurface(Game::renderer, this->txt_surface);

    SDL_FreeSurface(this->txt_surface);
}

void Text::draw()
{
    TextureManager::draw(this->txt_texture, *this->txt_src, *this->txt_dest);
}

void Text::set_text(const std::string& text)
{
    if (text != this->text)
    {
        SDL_DestroyTexture(this->txt_texture);
        this->text = text;
        this->create_text();
    } else this->text = text;
}

std::string& Text::get_text()
{
    return this->text;
}
