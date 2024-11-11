#include "static.hpp"
#include <iostream>

// Constructor
API::API()
{
    std::cout << "Constructor ran..." << std::endl;
};
// Destructor
API::~API()
{
    std::cout << "Destructor ran..." << std::endl;
};
// Static member variables
const int API::POSITIVE = 10;
const int API::NEGATIVE = -10;
// Static member functions
int API::getNegative()
{
    return API::NEGATIVE;
};
int API::getPositive()
{
    return API::POSITIVE;
}