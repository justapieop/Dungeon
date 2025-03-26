#ifndef UTILS_HPP
#define UTILS_HPP
#include "vector"

class Utils
{
public:
    static void log_err_and_exit(const char* msg);
    static std::vector<std::vector<int>> load_matrix(const char* path, int m, int n);
};


#endif //UTILS_HPP
