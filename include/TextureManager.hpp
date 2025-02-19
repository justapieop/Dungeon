//
// Created by JustAPie on 2/8/2025.
//

#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP
#include "SDL2/SDL.h"
#include "string"

class TextureManager {
public:
    static SDL_Texture* load_texture(const std::string& path);
};



#endif //TEXTUREMANAGER_HPP
