//
// Created by JustAPie on 2/9/2025.
//

#ifndef SCENE_HPP
#define SCENE_HPP
#include "SceneState.hpp"
#include "Object.hpp"
#include "string"

class Scene {
public:
    explicit Scene(SDL_Renderer* renderer);
    virtual ~Scene();

    void set_bg(const std::string& path, int x, int y, int w, int h);
    [[nodiscard]] Object* get_bg() const {
        return this->bg;
    }

    virtual void render() = 0;
    virtual void set_next_scene() = 0;
    virtual void update() = 0;
    [[nodiscard]] Scene* get_next_scene() const { return this->next; }
private:
    Scene* next{};
    int state = SCENE_RENDER;
    Object* bg{};
protected:
    SDL_Renderer* renderer;
};



#endif //SCENE_HPP
