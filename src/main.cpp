#include "Constants.hpp"
#include "Game.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_main.h"

Game* game = nullptr;
unsigned int frame_time = 0, frame_start = 0;

int main(int argc, char* argv[])
{
    game = new Game();

    game->init("Dungeon", SCREEN_WIDTH, SCREEN_HEIGHT);

    while (game->running())
    {
        frame_start = SDL_GetTicks();
        game->handle_events();
        game->update();
        game->render();

        frame_time = SDL_GetTicks() - frame_start;
        if (frame_time < MIN_FRAME_TIME)
        {
            SDL_Delay(MIN_FRAME_TIME - frame_time);
        }
    }

    game->clean();
    delete game;
    game = nullptr;
    return 0;
}
