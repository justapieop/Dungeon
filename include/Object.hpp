//
// Created by JustAPie on 2/18/2025.
//

#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "SDL2/SDL.h"
#include "string"

class Object {
public:
    explicit Object(const std::string& sheet);
    ~Object();

    void update();
    void render() const;
    void set_pos(int x, int y);
    void set_size(int w, int h);
private:
    int x = 0, y = 0;
    SDL_Texture* texture;
    SDL_Rect src{}, dest{};
};

#endif //OBJECT_HPP
