#ifndef SELECTION_HPP
#define SELECTION_HPP
#include "SDL2/SDL.h"
#include "Text.hpp"
#include "string"

class Selection
{
public:
    Selection();
    Selection(const int x, const int y, const std::string& label);
    ~Selection();

    void draw();

    void set_label_text(const std::string& label_text);
    std::string& get_label_text();
    bool active() const;
    void set_active(bool is_active);
private:
    SDL_Rect *button_src, *button_dest, *selection_src, *selection_dest, *label_src;
    SDL_Texture *selection, *button;
    bool is_active;
    std::string label_text;

    Text *txt;
};
#endif //SELECTION_HPP
