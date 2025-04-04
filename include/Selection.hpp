#ifndef SELECTION_HPP
#define SELECTION_HPP
#include "SDL2/SDL.h"
#include "string"

class Selection
{
public:
    Selection();
    Selection(const int x, const int y, const std::string& label);
    ~Selection();

    void draw();
    void update();

    void set_label_text(const std::string& label_text);
    std::string& get_label_text();
    bool active() const;
    void set_active(bool is_active);
private:
    SDL_Rect *button_src, *button_dest, *selection_src, *selection_dest, *label_src, *label_dest;
    SDL_Texture *selection, *button, *label;
    SDL_Surface *label_surface;
    bool is_active;
    std::string label_text;
};
#endif //SELECTION_HPP
