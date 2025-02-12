//
// Created by JustAPie on 2/12/2025.
//

#include "../../include/Button.hpp"
#include "string"

Button::Button(const std::string &sheet, SDL_Renderer *renderer): Object(sheet, renderer) {

}

Button::~Button() = default;

void Button::set_label(const std::string &label) {
    this->label = label;
}
