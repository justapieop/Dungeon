//
// Created by JustAPie on 2/7/2025.
//

#include "Utils.hpp"
#include "SDL2/SDL.h"

void Utils::log_err_and_exit(const char* msg)
{
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, msg);
    SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Quitting...");
    SDL_Quit();
}
