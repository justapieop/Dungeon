#ifndef ENEMYCOMPONENT_HPP
#define ENEMYCOMPONENT_HPP
#include "ECS.hpp"
class EnemyComponent : public Component
{
public:
    EnemyComponent();
    ~EnemyComponent() override;

    void init() override;
    void update() override;
    void draw() override;
private:
};
#endif //ENEMYCOMPONENT_HPP
