#include "../../include/Map.hpp"
#include "../../include/TextureManager.hpp"
#include "../../include/Utils.hpp"
#include "filesystem"

Map::Map() {
    this->is_loaded = false;
    this->src.x = this->src.y = this->dest.x = this->dest.y = 0;
    this->src.w = this->dest.w = 16;
    this->src.h = this->dest.h = 16;
}

Map::~Map() {
    for (SDL_Texture* texture : this->textures) {
        SDL_DestroyTexture(texture);
    }
    this->textures.clear();
}

void Map::draw() {
    for (int i = 0; i < this->map.size(); i++) {
        for (int j = 0; j < this->map[i].size(); j++) {
            const int type = this->map[i][j];
            this->dest.x = j * 16;
            this->dest.y = i * 16;
            if (type >= 0)
                TextureManager::draw(this->textures[type], this->src,
                                     this->dest);
        }
    }
}

void Map::load(const std::string& path) {
    this->map.resize(27);
    this->map = Utils::load_matrix(path.c_str(), 27, 48);
    this->is_loaded = true;
}

void Map::load_textures(const std::string& path) {
    for (const std::filesystem::path dir(path);
         auto& p : std::filesystem::directory_iterator(dir)) {
        if (p.is_regular_file()) {
            this->textures.push_back(
                TextureManager::load_texture(p.path().string()));
        }
    }
}

std::vector<std::vector<int>> Map::get_map() const { return this->map; }

bool Map::loaded() const { return this->is_loaded; }
