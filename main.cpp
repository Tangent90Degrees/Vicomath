#include <iostream>
#include "src/quaternion.hpp"
#include "src/utils/timer.hpp"

using namespace math;

int main()
{
    timer timer;

    quaternion a = {1, 2, 3, 4};
    a[X] = 9;
    std::cout << (a + a)[Y] << std::endl;

    std::cout << timer.passed_time(MICROSECOND) << std::endl;
}