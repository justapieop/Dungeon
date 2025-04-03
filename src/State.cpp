#include "State.hpp"

State::State()
{
    this->args = std::vector<std::any>();
}
State::~State() = default;

std::vector<std::any>& State::get_args()
{
    return this->args;
}
