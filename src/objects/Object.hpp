//
// Created by JustAPie on 2/8/2025.
//

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "SDL2/SDL.h"
#include "string"

class Object {
public:
    Object(const std::string& sheet, SDL_Renderer* renderer);
    ~Object();

    void set_pos_src(int x, int y);
    void set_size_src(int w, int h);
    void set_pos_dest(int x, int y);
    void set_size_dest(int w, int h);

    void update();
    void render() const;
private:
    SDL_Renderer* renderer;
    SDL_Texture* texture{};
    SDL_Rect source{}, dest{};
};



#endif //OBJECT_HPP
