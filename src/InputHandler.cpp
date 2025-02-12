//
// Created by JustAPie on 2/8/2025.
//

#include "InputHandler.hpp"
#include "../include/Action.hpp"
#include "map"

InputHandler::InputHandler() {
    this->keymap = std::map<const char*, Action>();
}

InputHandler::~InputHandler() {
    this->keymap.clear();
}

void InputHandler::set_keybind(const char* key, const Action& action) {
    this->keymap.at(key) = action;
}

