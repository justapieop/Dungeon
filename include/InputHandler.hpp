//
// Created by JustAPie on 2/8/2025.
//
#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP
#include "Action.hpp"
#include "map"

class InputHandler {
public:
    InputHandler();
    ~InputHandler();

    void set_keybind(const char* key, const Action& action);
private:
    std::map<const char*, Action> keymap;
};

#endif //INPUTHANDLER_HPP
