#include "InventoryComponent.hpp"
#include "string"
#include "unordered_map"

InventoryComponent::InventoryComponent() = default;
InventoryComponent::~InventoryComponent() = default;

void InventoryComponent::draw() {}

void InventoryComponent::init() {
    this->inventory = std::unordered_map<std::string, int>();
}

void InventoryComponent::update() {}
