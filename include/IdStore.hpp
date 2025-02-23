//
// Created by JustAPie on 2/23/2025.
//

#ifndef IDSTORE_HPP
#define IDSTORE_HPP

class IdStore {
public:
    static int get_id();

    template <typename T>
    static int get_id();
};

#endif //IDSTORE_HPP
