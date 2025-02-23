//
// Created by JustAPie on 2/23/2025.
//
#include "IdStore.hpp"

int IdStore::get_id() {
    static int last = 0;
    return last++;
}

template<typename T>
int IdStore::get_id() {
    static int type = get_id();
    return type;
}

