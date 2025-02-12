//
// Created by JustAPie on 2/8/2025.
//

#include "../../include/Action.hpp"

Action::Action(Object *object) {
    this->object = object;
}

Action::~Action() {
    this->object = nullptr;
}

