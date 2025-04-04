#include "Selection.hpp"
#include "SDL2/SDL.h"
#include "Game.hpp"
#include "TextureManager.hpp"

Selection::Selection()
{
    this->is_active = false;
    this->label_text = "";
}

Selection::Selection(int x, int y, const std::string& label)
{
    this->is_active = false;
    this->label_text = label;

    this->button_src = this->selection_src = new SDL_Rect(0, 0, 120, 120);
    this->button_dest = this->selection_dest = new SDL_Rect(x, y, 60, 60);

    this->button = TextureManager::load_texture("./assets/misc/button.png");
    this->selection = TextureManager::load_texture("./assets/misc/selection.png");

    this->label_surface = TTF_RenderText_Blended(Game::font, this->label_text.c_str(), { 255, 255, 255, SDL_ALPHA_OPAQUE });
    this->label = SDL_CreateTextureFromSurface(Game::renderer, this->label_surface);
    SDL_FreeSurface(this->label_surface);
    this->label_src = new SDL_Rect(0, 0, 128, 128);
    this->label_dest = new SDL_Rect(x + this->button_dest->w + 10, y + this->button_dest->h / 2, 100, 20);
}

Selection::~Selection() = default;

void Selection::draw()
{
    TextureManager::draw(this->button, *this->button_src, *this->button_dest);
    if (this->active()) TextureManager::draw(this->selection, *this->selection_src, *this->selection_dest);
    TextureManager::draw(this->label, *this->label_src, *this->label_dest);
}

void Selection::set_label_text(const std::string& label_text)
{
    this->label_text = label_text;
}

std::string& Selection::get_label_text()
{
    return this->label_text;
}

bool Selection::active() const
{
    return this->is_active;
}

void Selection::set_active(bool is_active)
{
    this->is_active = is_active;
}
