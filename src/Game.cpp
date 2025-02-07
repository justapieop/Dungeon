//
// Created by JustAPie on 2/7/2025.
//

#include "Game.hpp"
#include <SDL2/SDL.h>

Game::Game() {
    this->is_running = false;
    this->window = nullptr;
    this->renderer = nullptr;
}

Game::~Game() {
    this->is_running = NULL;
    this->window = nullptr;
    this->renderer = nullptr;
}

void Game::init(const char *title, int w, int h) {
    SDL_Log("Initializing game engine");
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        SDL_Log("Game engine initialized");
        SDL_Log("Creating window");
        this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_HIDDEN);
        if (this->window != nullptr) {
            SDL_Log("Window created");
        } else {
            SDL_Log("Failed to create window");
            return;
        }

        SDL_Log("Creating renderer");
        SDL_Log("Finding GPU for the renderer to work");
        if (SDL_GetNumRenderDrivers() < 0) {
            SDL_Log("No GPU present");
            return;
        }

        for (int i = 0; i < SDL_GetNumRenderDrivers(); i++) {
            if (SDL_GetRenderDriverInfo(i, &this->info) == 0) {
                if (strstr(this->info.name, "opengl") || strstr(this->info.name, "vulkan")) {
                    this->renderer = SDL_CreateRenderer(this->window, i, SDL_RENDERER_ACCELERATED);
                    SDL_Log("Using detected dGPU as the render device");
                    break;
                }
            }
        }

        if (this->renderer == nullptr) {
            SDL_Log("Falling back to default GPU");
            this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
        }

        if (this->renderer != nullptr) {
            SDL_Log("Renderer created");
        } else {
            SDL_Log("Failed to create a renderer");
            this->window = nullptr;
            return;
        }

        this->is_running = true;
        SDL_ShowWindow(this->window);
    } else {
        SDL_Log("Game engine initialization failed");
    }
}

void Game::handle_events() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            SDL_Log("Game quitted");
            this->is_running = false;
            break;
        default:
            break;
    }
}

void Game::update() {

}

void Game::render() const {
    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);
}

void Game::clean() {
    SDL_Log("Destroying window and renderer");
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
    this->is_running = false;
}


