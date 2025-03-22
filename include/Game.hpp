#ifndef GAME_HPP
#define GAME_HPP
#include "ECS.hpp"
#include "Map.hpp"
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

    [[nodiscard]] bool running() const;
    static SDL_Renderer *renderer;
    static SDL_Event event;
    static Map *coll_map;

private:
    bool is_running{};
    SDL_RendererInfo info{};
    SDL_Window *window{};
    Map *map{};
    ComponentManager* component_manager{};
};


#endif //GAME_HPP
