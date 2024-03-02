#include <iostream>

#include "vicomath.h"
#include "src/point.hpp"

using namespace math;

int main() {
    timer timer;

    point a = {1.0, 2.7, 3.4};
    vector v = {1, 2, 3};

    point b = a + v;

    std::cout << "Time passed " << timer.passed_time(MICROSECOND) << " ms." << std::endl;
}