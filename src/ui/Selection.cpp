#include "../../include/Selection.hpp"
#include "../../cmake-build-release/external/SDL/include/SDL2/SDL.h"
#include "../../include/Action.hpp"
#include "../../include/Game.hpp"
#include "../../include/Text.hpp"
#include "../../include/TextureManager.hpp"

Selection::Selection(const int x, const int y, const std::string& label) {
    this->is_active = false;
    this->label_text = label;

    this->button_src = this->selection_src = new SDL_Rect(0, 0, 120, 120);
    this->button_dest = this->selection_dest = new SDL_Rect(x, y, 60, 60);

    this->button = TextureManager::load_texture("./assets/misc/button.png");
    this->selection =
        TextureManager::load_texture("./assets/misc/selection.png");

    this->txt =
        new Text(x + this->button_dest->w + 10, y + this->button_dest->h / 2,
                 100, 20, this->label_text);
    this->txt->create_text();

    this->action = Action::ATTACK;
}

Selection::~Selection() = default;

void Selection::draw() const {
    TextureManager::draw(this->button, *this->button_src, *this->button_dest);
    if (this->active())
        TextureManager::draw(this->selection, *this->selection_src,
                             *this->selection_dest);
    this->txt->draw();
}

void Selection::set_label_text(const std::string& label_text) {
    this->label_text = label_text;
}

std::string& Selection::get_label_text() { return this->label_text; }

bool Selection::active() const { return this->is_active; }

void Selection::set_active(bool is_active) { this->is_active = is_active; }

Action Selection::get_action() const { return this->action; }

void Selection::set_action(const Action action) { this->action = action; }
