//
// Created by JustAPie on 2/8/2025.
//

#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP
#include "SDL.h"


class TextureManager {
    static SDL_Texture* load_texture(const char* path, SDL_Renderer* renderer);
};



#endif //TEXTUREMANAGER_HPP
