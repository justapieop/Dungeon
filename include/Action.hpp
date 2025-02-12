//
// Created by JustAPie on 2/8/2025.
//

#ifndef ACTION_HPP
#define ACTION_HPP
#include "Object.hpp"


class Action {
public:
    explicit Action(Object* object);
    ~Action();

    void execute();
private:
    Object* object;
};



#endif //ACTION_HPP
