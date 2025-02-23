//
// Created by JustAPie on 2/23/2025.
//

#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "bitset"
#include "IdStore.hpp"
#include "vector"

class Component;

#include "Component.hpp"

class Entity {
public:
    void draw();
    [[nodiscard]] bool active() const;
    void destroy();
    void update();
    template <typename T> [[nodiscard]] bool has_component() const;
    template <typename T, typename ...TArgs> T& add_components(TArgs&& ...args);
    template <typename T> T& get_components();

private:
    bool is_active = false;
    std::vector<Component*> components;
    std::vector<Component*> unique_components;
    std::bitset<32> component_bitset;
};


#endif //ENTITY_HPP
