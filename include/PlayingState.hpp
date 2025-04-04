#ifndef PLAYINGSTATE_HPP
#define PLAYINGSTATE_HPP
#include "ECS.hpp"
#include "State.hpp"
#include "Map.hpp"
#include "SDL_mixer.h"

class PlayingState : public State
{
public:
    PlayingState();
    ~PlayingState() override;

    void update() override;
    void draw() override;
private:
    ComponentManager *component_manager{};
    Entity *player, *enemy;
    Mix_Music *music;
};
#endif //PLAYINGSTATE_HPP
