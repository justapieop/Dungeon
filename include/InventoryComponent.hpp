#ifndef INVENTORYCOMPONENT_HPP
#define INVENTORYCOMPONENT_HPP
#include "ECS.hpp"
#include "unordered_map"
#include "string"

class InventoryComponent : public Component
{
public:
    InventoryComponent();
    ~InventoryComponent();

    void init() override;
    void draw() override;
    void update() override;
private:
    std::unordered_map<std::string, int> inventory;
};
#endif //INVENTORYCOMPONENT_HPP
