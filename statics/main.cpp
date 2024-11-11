/* Static member variables in C++ */
#include "static.hpp"
#include <iostream>

int main(void)
{
    std::cout << API::NEGATIVE << std::endl;
    std::cout << API::POSITIVE << std::endl;
    std::cout << API::getNegative() << std::endl;
    std::cout << API::getPositive() << std::endl;
    return 0;
}