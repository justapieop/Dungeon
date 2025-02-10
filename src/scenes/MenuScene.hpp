//
// Created by JustAPie on 2/10/2025.
//

#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP

#include "Scene.hpp"
#include "SDL2/SDL.h"

class MenuScene final : public Scene {
public:
    explicit MenuScene(SDL_Renderer* renderer);
    ~MenuScene() override;

    void render() override;
    void update() override;
    void set_next_scene() override;
};



#endif //MENUSCENE_HPP
