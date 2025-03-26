#ifndef MAP_HPP
#define MAP_HPP
#include "SDL2/SDL.h"
#include "vector"
#include "string"

class Map
{
public:
    Map();
    ~Map();

    void load(const std::string& path);
    void draw();
    void load_textures(const std::string& path);

    bool loaded() const;
    std::vector<std::vector<int>> get_map() const;
private:
    SDL_Rect src{}, dest{};
    std::vector<SDL_Texture*> textures;
    bool is_loaded;
    std::vector<std::vector<int>> map;
};

#endif //MAP_HPP
