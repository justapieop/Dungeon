//
// Created by JustAPie on 2/7/2025.
//

#ifndef GAME_HPP
#define GAME_HPP
#include "SDL2/SDL.h"
#include "string"
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
    static SDL_Renderer* renderer;
private:
    bool is_running;
    SDL_RendererInfo info{};
    SDL_Event event{};
    SDL_Window* window;

};



#endif //GAME_HPP
