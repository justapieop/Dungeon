//
// Created by JustAPie on 2/12/2025.
//

#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "Object.hpp"
#include "string"

class Button : public Object {
public:
    Button(const std::string& sheet, SDL_Renderer* renderer);
    ~Button();

    void set_label(const std::string &label);
private:
    std::string label;
};



#endif //BUTTON_HPP
