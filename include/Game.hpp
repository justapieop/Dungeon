#ifndef GAME_HPP
#define GAME_HPP
#include "ECS.hpp"
#include "Map.hpp"
#include "SDL2/SDL.h"
#include "SDL_ttf.h"
#include "StateManager.hpp"
#include "string"

class Game
{
public:
    Game();
    ~Game();

    void init(const std::string& title, int w, int h);
    void handle_events();
    void update() const;
    void render() const;
    void clean();

    static bool running();
    static StateManager* state_manager;
    static SDL_Renderer* renderer;
    static SDL_Event event;
    static Map *coll_map, *map;
    static TTF_Font* font;
    static void force_stop();
private:
    static bool is_running;
    SDL_RendererInfo info{};
    SDL_Window* window{};
};


#endif //GAME_HPP
