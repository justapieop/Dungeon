//
// Created by JustAPie on 2/7/2025.
//
#include "Game.hpp"
#include "SDL.h"
#include "SDL_main.h"

Game* game;
constexpr int FPS = 60, min_frame_time = 1000 / FPS;
unsigned int frame_time, frame_start;

int main(int argc, char *argv[]) {
    game = new Game();

    game->init("Dungeon", 1366, 768);

    while (game->running()) {
        frame_start = SDL_GetTicks();
        game->handle_events();
        game->update();
        game->render();

        frame_time = SDL_GetTicks() - frame_start;
        if (frame_time < min_frame_time) {
            SDL_Delay(min_frame_time - frame_time);
        }
    }

    game->clean();
    delete game;
    game = nullptr;
    return 0;
}