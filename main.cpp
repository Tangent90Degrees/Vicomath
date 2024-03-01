#include <iostream>
#include "src/quaternion.hpp"
#include "src/utils/timer.hpp"

using namespace math;

int main()
{
    timer timer;

    quaternion a = {1, 2, 3, 4};
    quaternion b = {5, 2, 1, 7};
    quaternion c = a * b;

    std::cout << "Time passed " << timer.passed_time(MICROSECOND) << " ms." << std::endl;
}