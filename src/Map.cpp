//
// Created by JustAPie on 2/19/2025.
//
#include "Map.hpp"
#include "fstream"
#include "TextureManager.hpp"
#include "Utils.hpp"
#include "filesystem"
#include "iostream"

Map::Map()
{
    this->is_loaded = false;
    this->src.x = this->src.y = this->dest.x = this->dest.y = 0;
    this->src.w = this->dest.w = 16;
    this->src.h = this->dest.h = 16;
}

Map::~Map()
{
    for (SDL_Texture* texture : this->textures)
    {
        SDL_DestroyTexture(texture);
    }
    this->textures.clear();
}

std::vector<std::vector<int>> Map::map;

void Map::draw()
{
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            const int type = map[i][j];
            this->dest.x = j * 16;
            this->dest.y = i * 16;
            TextureManager::draw(this->textures[type], this->src, this->dest);
        }
    }
}

void Map::load(const std::string& path)
{
    map.resize(27);
    SDL_Log("Loading map...");
    if (std::ifstream map_data(path); map_data.is_open())
    {
        for (auto& i : map)
        {
            i.resize(48);
            for (int& j : i)
                map_data >> j;
        }
        SDL_Log("Map data successfully loaded");
        this->is_loaded = true;
        map_data.close();
    }
    else
    {
        Utils::log_err_and_exit("Failed to find map.data");
    }

    SDL_Log("Loading map textures");
    for (const std::filesystem::path dir("./assets/"); auto& p : std::filesystem::directory_iterator(dir))
    {
        if (p.is_regular_file())
        {
            this->textures.push_back(TextureManager::load_texture(p.path().string()));
        }
    }
    SDL_Log("Loaded map textures");
}

bool Map::loaded() const
{
    return this->is_loaded;
}
