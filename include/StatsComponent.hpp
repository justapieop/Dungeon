#ifndef STATSCOMPONENT_HPP
#define STATSCOMPONENT_HPP
#include "ECS.hpp"

class StatsComponent : public Component
{
public:
    StatsComponent();
    ~StatsComponent() override;

    void draw() override;
    void update() override;
    void init() override;

    float get_hp() const;
    float get_atk() const;
    float get_def() const;

    void set_hp(float hp);
    void set_atk(float atk);
    void set_def(float def);
private:
    float hp, atk, def;
};
#endif //STATSCOMPONENT_HPP
