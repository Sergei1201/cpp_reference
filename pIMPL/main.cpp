#include "person.hpp"
#include <iostream>

int main(void)
{
    Person p1{"Sergei", "Sokolov"};
    std::cout << p1.getName() << std::endl;
    return 0;
}