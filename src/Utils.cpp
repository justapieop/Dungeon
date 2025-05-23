#include "Utils.hpp"
#include "SDL2/SDL.h"
#include "fstream"
#include "vector"
#include "sstream"

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

std::string Utils::round_float(const float f) {
    const float r = std::round(f * 100.0f) / 100.0f;

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << r;
    return oss.str();
}

float Utils::rng(const int min, const int max) {
    srand(time(nullptr));
    return rand() % (max - min + 1) + min;
}
