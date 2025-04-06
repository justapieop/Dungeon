#ifndef UTILS_HPP
#define UTILS_HPP
#include "vector"
#include "string"
#include "iomanip"

class Utils
{
public:
    static void log_err_and_exit(const char* msg);
    static std::vector<std::vector<int>> load_matrix(const char* path, int m, int n);
    static std::string round_float(float f);
    static float rng(int min, int max);
};


#endif //UTILS_HPP
