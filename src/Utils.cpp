//
// Created by JustAPie on 2/7/2025.
//

#include "Utils.hpp"
#include <SDL2/SDL.h>
#include <cstring>

void Utils::log_err_and_exit(const char *msg) {
    SDL_Log(msg);
    SDL_Quit();
}
