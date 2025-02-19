//
// Created by JustAPie on 2/7/2025.
//

#include "Game.hpp"
#include "Object.hpp"
#include "SDL_image.h"
#include "Utils.hpp"
#include "SDL.h"
#include "SDL_ttf.h"
#include "string"

Object* player;

SDL_Renderer* Game::renderer = nullptr;

Game::Game() {
    this->is_running = false;
    this->window = nullptr;
}

Game::~Game() {
    this->is_running = NULL;
    this->window = nullptr;
    renderer = nullptr;
}

void Game::init(const std::string& title, const int w, const int h) {
    SDL_Log("Initializing game engine");
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        SDL_Log("Game engine initialized");
        SDL_Log("Creating window");
        this->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_HIDDEN);
        if (this->window != nullptr) {
            SDL_Log("Window created");
        } else {
            Utils::log_err_and_exit("Failed to create window");
            return;
        }

        SDL_Log("Creating renderer");
        SDL_Log("Finding GPU for the renderer to work");
        if (SDL_GetNumRenderDrivers() < 0) {
            Utils::log_err_and_exit("No GPU present");
            return;
        }

        for (int i = 0; i < SDL_GetNumRenderDrivers(); i++) {
            if (SDL_GetRenderDriverInfo(i, &this->info) == 0) {
                if (strstr(this->info.name, "opengl") || strstr(this->info.name, "vulkan")) {
                    renderer = SDL_CreateRenderer(this->window, i, SDL_RENDERER_ACCELERATED);
                    SDL_Log("Using detected dGPU as the render device");
                    break;
                }
            }
        }

        if (renderer == nullptr) {
            SDL_Log("Falling back to default GPU");
            renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
        }

        if (renderer != nullptr) {
            SDL_Log("Renderer created");
        } else {
            Utils::log_err_and_exit("Failed to create a renderer");
            this->window = nullptr;
            return;
        }

        this->is_running = true;
        SDL_Log("Drawing windows");
        SDL_ShowWindow(this->window);
        SDL_Log("Window drawn");

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        player = new Object("assets/play.png");
        player->set_pos(0, 0);
        player->set_size(32, 32);
    } else {
        Utils::log_err_and_exit("Game engine initialization failed");
    }
}

void Game::handle_events() {
    SDL_PollEvent(&this->event);

    switch (this->event.type) {
        case SDL_QUIT:
            SDL_Log("Game quit");
            this->is_running = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    player->update();
}

void Game::render() const {
    SDL_RenderClear(renderer);
    player->render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_Log("Destroying window and renderer");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
    this->is_running = false;
}


