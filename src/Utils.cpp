//
// Created by JustAPie on 2/7/2025.
//

#include "../include/Utils.hpp"
#include <SDL2/SDL.h>
#include <cstring>

void Utils::log_err_and_exit(const char *msg) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, msg);
    SDL_Quit();
}
