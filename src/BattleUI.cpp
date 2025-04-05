#include "BattleUI.hpp"
#include "CurrentStatComponent.hpp"
#include "Game.hpp"
#include "SDL2/SDL.h"
#include "Selection.hpp"
#include "StatsUI.hpp"
#include "TextureManager.hpp"

BattleUI::BattleUI()
{
    this->current = 0;
    this->sel = std::vector<Selection*>();

    this->sel.push_back(
        new Selection(30, 350, "Attack")
    );

    this->sel.push_back(
        new Selection(250, 350, "Heal")
    );

    this->sel.push_back(
        new Selection(450, 350, "Flee")
    );
    this->player = new StatsUI(10, 100);
    this->player->set_stats(0.0f, 0.0f, 0.0f);
    this->enemy = new StatsUI(660, 100);
    this->enemy->set_stats(0.0f, 0.0f, 0.0f);
}

BattleUI::~BattleUI() = default;

void BattleUI::draw()
{
    for (int i = 0; i < this->sel.size(); i++)
    {
        this->sel[i]->draw();
    }
    this->player->draw();
    this->enemy->draw();
}

int BattleUI::get_current() const
{
    return this->current;
}

std::vector<Selection*>& BattleUI::get_sel()
{
    return this->sel;
}

void BattleUI::set_current(int current)
{
    this->current = current;
}

void BattleUI::trigger_action(Entity& entity, const Action action)
{

}

void BattleUI::update(Entity& player, Entity& enemy)
{
    CurrentStatComponent *player_current = &player.get_component<CurrentStatComponent>(), *enemy_current = &enemy.get_component<CurrentStatComponent>();
    this->player->set_stats(player_current->get_hp(), player_current->get_atk(), player_current->get_def());
    this->enemy->set_stats(enemy_current->get_hp(), enemy_current->get_atk(), enemy_current->get_def());

    if (Game::event.type == SDL_KEYDOWN)
    {
        switch (Game::event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                ++this->current;
                break;
            case SDLK_LEFT:
                --this->current;
                break;
            case SDLK_SPACE:
                break;
            default:
                break;
        }
    }

    if (this->current >= this->sel.size()) this->current = this->sel.size() - 1;
    if (this->current < 0) this->current = 0;

    for (int i = 0; i < this->sel.size(); i++)
    {
        this->sel[i]->set_active(false);
        if (i == this->current)
        {
            this->sel[i]->set_active(true);
        }
    }


}
