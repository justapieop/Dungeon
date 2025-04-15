#include "Text.hpp"
#include "Game.hpp"
#include "SDL2/SDL.h"
#include "TextureManager.hpp"
#include "string"

Text::Text(const int x, const int y, const int w, const int h,
           const std::string& text)
    : txt_surface(nullptr), txt_texture(nullptr) {
    this->text = text;
    this->txt_src = new SDL_Rect(0, 0, w, h);
    this->txt_dest = new SDL_Rect(x, y, w, h);
}

Text::~Text() = default;

void Text::create_text() {
    this->txt_surface = TTF_RenderText_Blended(
        Game::font, this->text.c_str(), {255, 255, 255, SDL_ALPHA_OPAQUE});

    this->txt_texture =
        SDL_CreateTextureFromSurface(Game::renderer, this->txt_surface);

    SDL_FreeSurface(this->txt_surface);
}

void Text::draw() const {
    TextureManager::draw(this->txt_texture, *this->txt_src, *this->txt_dest);
}

void Text::set_text(const std::string& text) {
    if (text != this->text) {
        SDL_DestroyTexture(this->txt_texture);
        this->text = text;
        this->create_text();
    } else
        this->text = text;
}

std::string& Text::get_text() { return this->text; }

void Text::clear() const {
    if (this->txt_texture)
        SDL_DestroyTexture(this->txt_texture);
}
