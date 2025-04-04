#include "BattleUI.hpp"
#include "SDL2/SDL.h"
#include "TextureManager.hpp"

BattleUI::BattleUI()
{
    this->attack = new SDL_Rect(0, 0, 120, 120);
    this->heal = new SDL_Rect(0, 0, 120, 120);
    this->attack_dest = new SDL_Rect(10, 300, 120, 120);
    this->heal_dest = new SDL_Rect(380, 300, 120, 120);
    this->button = TextureManager::load_texture("./assets/misc/button.png");
}

BattleUI::~BattleUI() = default;

void BattleUI::draw()
{
    TextureManager::draw(this->button, *this->attack, *this->attack_dest);
    TextureManager::draw(this->button, *this->heal, *this->heal_dest);
}

void BattleUI::update(const Entity& player, const Entity& enemy)
{
    const Uint8 *key_states = SDL_GetKeyboardState(nullptr);
}
