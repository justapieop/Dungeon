#include "Game.hpp"
#include "CollisionComponent.hpp"
#include "SDL2/SDL.h"
#include "SDL_image.h"
#include "StateManager.hpp"
#include "Utils.hpp"
#include "string"

Game::Game() = default;

Game::~Game() = default;

bool Game::is_running = false;

SDL_Renderer* Game::renderer = nullptr;

Map* Game::coll_map = nullptr;
Map* Game::map = nullptr;

SDL_Event Game::event;

StateManager* Game::state_manager = nullptr;

TTF_Font* Game::font = nullptr;

void Game::init(const std::string& title, const int w, const int h) {
    SDL_Log("Initializing game engine");
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        SDL_Log("Game engine initialized");
        SDL_Log("Creating window");
        this->window =
            SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_HIDDEN);
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
                if (strstr(this->info.name, "opengl") ||
                    strstr(this->info.name, "vulkan")) {
                    renderer = SDL_CreateRenderer(
                        this->window, i,
                        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
                    SDL_Log("Using detected dGPU as the render device");
                    SDL_Log("Using %s graphics engine", this->info.name);
                    break;
                }
            }
        }

        if (renderer == nullptr) {
            SDL_Log("Falling back to default GPU");
            renderer = SDL_CreateRenderer(this->window, -1,
                                          SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
        }

        if (renderer != nullptr) {
            SDL_Log("Renderer created");
        } else {
            Utils::log_err_and_exit("Failed to create a renderer");
            this->window = nullptr;
            return;
        }

        SDL_Log("Initializing TTF font loader");
        if (TTF_Init() == -1) {
            Utils::log_err_and_exit("Failed to initialize font loader");
            return;
        }

        SDL_Log("Initialized TTF font loader");
        SDL_Log("Loading font");
        font = TTF_OpenFont("./fonts/EightBitDragon-anqx.ttf", 18);

        if (font == nullptr) {
            Utils::log_err_and_exit("Failed to load font");
            return;
        }
        SDL_Log("Font loaded");

        is_running = true;

        SDL_Log("Loading collision map");
        coll_map = new Map();
        coll_map->load("./data/collision.data");
        coll_map->load_textures("./assets/collision/");

        SDL_Log("Loading terrain map");
        map = new Map();
        map->load("./data/map.data");
        map->load_textures("./assets/tiles/");

        SDL_Log("Loading audio player");
        if (Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
            Utils::log_err_and_exit("Failed to load audio player");
            return;
        }

        state_manager = new StateManager();
        state_manager->set_state(GameState::MENU);

        if (map->loaded()) {
            SDL_Log("Drawing windows");
            SDL_ShowWindow(this->window);
            SDL_Log("Window drawn");
        }
    } else {
        Utils::log_err_and_exit("Game engine initialization failed");
    }
}

void Game::handle_events() const {
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Game quit");
            is_running = false;
            break;
        default:
            break;
    }
}

void Game::update() const { state_manager->update(); }

void Game::render() const {
    SDL_RenderClear(renderer);
    state_manager->draw();
    SDL_RenderPresent(renderer);
}

void Game::clean() const {
    SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Destroying window and renderer");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(this->window);
    IMG_Quit();
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
    is_running = false;
}

bool Game::running() { return is_running; }

void Game::force_stop() { is_running = false; }
