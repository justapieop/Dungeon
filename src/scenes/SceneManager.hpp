//
// Created by JustAPie on 2/10/2025.
//

#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP
#include "Scene.hpp"
#include "SDL2/SDL.h"

class SceneManager {
public:
    explicit SceneManager(SDL_Renderer* renderer);
    ~SceneManager();

    void set_scene(Scene* scene);

    void render() const;
private:
    SDL_Renderer* renderer;
    Scene* current{};
};



#endif //SCENEMANAGER_HPP
