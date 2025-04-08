#include "StatsComponent.hpp"

StatsComponent::StatsComponent() = default;

StatsComponent::~StatsComponent() = default;

void StatsComponent::init() {
    this->set_hp(20.0f);
    this->set_atk(1.0f);
    this->set_def(5.0f);
}

void StatsComponent::update() {}

void StatsComponent::draw() {}

float StatsComponent::get_hp() const { return this->hp; }

float StatsComponent::get_atk() const { return this->atk; }

float StatsComponent::get_def() const { return this->def; }

void StatsComponent::set_hp(float hp) { this->hp = hp; }

void StatsComponent::set_atk(float atk) { this->atk = atk; }

void StatsComponent::set_def(float def) { this->def = def; }
