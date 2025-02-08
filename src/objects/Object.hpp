//
// Created by JustAPie on 2/8/2025.
//

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SDL2/SDL.h>

class Object {
public:
    Object(const char* sheet, SDL_Renderer* renderer);
    ~Object();

    void set_pos(int x, int y);

    void update();
    void render() const;
private:
    int x;
    int y;
    SDL_Renderer* renderer;
    SDL_Texture* texture{};
    SDL_Rect source{}, dest{};
};



#endif //OBJECT_HPP
