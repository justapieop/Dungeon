#include "StatsUI.hpp"
#include "CurrentStatComponent.hpp"
#include "ECS.hpp"
#include "Game.hpp"
#include "TextureManager.hpp"
#include "string"

StatsUI::StatsUI(const int x, const int y)
{
    this->hp_src = new SDL_Rect(0, 0, 100, 50);
    this->hp_dest = new SDL_Rect(x, y, 100, 50);
    this->atk_src = new SDL_Rect(0, 0, 100, 50);
    this->atk_dest = new SDL_Rect(x, y + this->hp_dest->h + 10, 100, 50);
    this->def_src = new SDL_Rect(0, 0, 100, 50);
    this->def_dest = new SDL_Rect(x, this->atk_dest->y + this->atk_dest->h + 10, 100, 50);

    this->hp = this->atk = this->def = -1.0f;
}

StatsUI::~StatsUI() = default;

void StatsUI::set_stats(const float hp, const float atk, const float def)
{
    if (this->hp != hp)
    {
        this->hp_surface = TTF_RenderText_Blended(Game::font, ("HP: " + std::to_string(hp)).c_str(), { 255, 255, 255, SDL_ALPHA_OPAQUE });
        this->hp_texture = SDL_CreateTextureFromSurface(Game::renderer, this->hp_surface);
        SDL_FreeSurface(this->hp_surface);
    }
    this->hp = hp;
    if (this->atk != atk)
    {
        this->atk_surface = TTF_RenderText_Blended(Game::font, ("ATK: " + std::to_string(atk)).c_str(), { 255, 255, 255, SDL_ALPHA_OPAQUE });
        this->atk_texture = SDL_CreateTextureFromSurface(Game::renderer, this->atk_surface);
        SDL_FreeSurface(this->atk_surface);
    }
    this->atk = atk;
    if (this->def != def)
    {
        this->def_surface = TTF_RenderText_Blended(Game::font, ("DEF: " + std::to_string(def)).c_str(), { 255, 255, 255, SDL_ALPHA_OPAQUE });
        this->def_texture = SDL_CreateTextureFromSurface(Game::renderer, this->def_surface);
        SDL_FreeSurface(this->def_surface);
    }
    this->def = def;
}

void StatsUI::draw()
{
    TextureManager::draw(this->hp_texture, *this->hp_src, *this->hp_dest);
    TextureManager::draw(this->atk_texture, *this->atk_src, *this->atk_dest);
    TextureManager::draw(this->def_texture, *this->def_src, *this->def_dest);
}
