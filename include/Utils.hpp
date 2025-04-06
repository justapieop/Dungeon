#ifndef UTILS_HPP
#define UTILS_HPP
#include "vector"
#include "string"
#include "cmath"
#include "sstream"
#include "iomanip"

class Utils
{
public:
    static void log_err_and_exit(const char* msg);
    static std::vector<std::vector<int>> load_matrix(const char* path, int m, int n);
    static std::string round_float(const float f) {
        const float r = std::round(f * 100.0f) / 100.0f;

        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << r;
        return oss.str();
    }
};


#endif //UTILS_HPP
