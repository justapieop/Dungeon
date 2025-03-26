#include "InventoryComponent.hpp"
#include "unordered_map"
#include "string"

InventoryComponent::InventoryComponent() = default;
InventoryComponent::~InventoryComponent() = default;

void InventoryComponent::draw()
{}

void InventoryComponent::init()
{
    this->inventory = std::unordered_map<std::string, int>();
}

void InventoryComponent::update()
{

}
