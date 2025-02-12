//
// Created by JustAPie on 2/7/2025.
//

#ifndef GAME_HPP
#define GAME_HPP
#include "Inputhandler.hpp"
#include "../cmake-build-debug/external/SDL/include/SDL2/SDL.h"
#include "string"
#include "SceneManager.hpp"

class Game {
public:
    Game();
    ~Game();

    void init(const std::string& title, int w, int h);
    void handle_events();
    void update();
    void render() const;
    void clean();

    [[nodiscard]] bool running() const { return this->is_running; }
private:
    bool is_running;
    SDL_RendererInfo info{};
    SDL_Window* window;
    SDL_Renderer* renderer;
    InputHandler* input_handler;
    SceneManager* scene_manager{};
};



#endif //GAME_HPP
