#include "Utils.hpp"
#include "SDL2/SDL.h"
#include "fstream"
#include "vector"

void Utils::log_err_and_exit(const char* msg) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", msg);
    SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Quitting...");
    SDL_Quit();
}

std::vector<std::vector<int>> Utils::load_matrix(const char* path, const int m,
                                                 const int n) {
    std::vector<std::vector<int>> temp;
    temp.resize(m);
    if (std::ifstream data(path); data.is_open()) {
        for (int i = 0; i < m; i++) {
            temp[i].resize(n);
            for (int j = 0; j < n; j++) {
                data >> temp[i][j];
            }
        }
        data.close();
    } else {
        SDL_Log("Failed to open %s", path);
    }
    return temp;
}
