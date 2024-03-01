#include <iostream>
#include "src/quaternion.hpp"
#include "src/vector.hpp"
#include "src/utils/timer.hpp"

using namespace math;

int main() {
    timer timer;

    vector a = {1, 2, 3};
    vector b = {5, 2, 1};
    vector c = a * 3 + b;

    std::cout << "Time passed " << timer.passed_time(MICROSECOND) << " ms." << std::endl;
}