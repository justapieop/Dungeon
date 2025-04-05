#ifndef TEXT_HPP
#define TEXT_HPP
#include "string"
#include "SDL2/SDL.h"

class Text
{
public:
    Text(const int x, const int y, const int w, const int h, const std::string& text);
    ~Text();

    void draw();
    void set_text(const std::string& text);
    std::string& get_text();
    void create_text();
private:
    std::string text;
    SDL_Rect *txt_src, *txt_dest;
    SDL_Surface *txt_surface;
    SDL_Texture *txt_texture;
};
#endif //TEXT_HPP
