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

Map::~Map() = default;

void Map::draw()
{
    for (int i = 0; i < this->map.size(); i++)
    {
        for (int j = 0; j < this->map[i].size(); j++)
        {
            const int type = this->map[i][j];
            this->dest.x = j * 16;
            this->dest.y = i * 16;
            TextureManager::draw(this->textures[type], this->src, this->dest);
        }
    }
}

void Map::load()
{
    this->map.resize(45);
    SDL_Log("Loading map...");
    if (std::ifstream map_data("data/map.data"); map_data.is_open())
    {
        for (auto& i : this->map)
        {
            i.resize(80);
            for (int& j : i)
                map_data >> j;
        }
        SDL_Log("Map successfully loaded");
        this->is_loaded = true;
        map_data.close();
    }
    else
    {
        Utils::log_err_and_exit("Failed to find map.data");
    }

    for (const std::filesystem::path dir("./assets/"); auto& p : std::filesystem::directory_iterator(dir))
    {
        if (p.is_regular_file())
        {
            this->textures.push_back(TextureManager::load_texture(p.path().string()));
        }
    }
}

bool Map::loaded() const
{
    return this->is_loaded;
}
