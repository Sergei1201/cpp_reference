/* Member initializer list in C++ */
#include <iostream>
#include "member.hpp"

int main(void)
{
    // Instantiate the class by dynamically allocating memory on the heap at runtime
    Person *p1{new (std::nothrow) Person{40, "Sergei", "Sokolov"}};
    std::cout << *(p1) << std::endl;
    std::cout << p1->greetings() << std::endl;
    // Return (deallocate) memory back to the OS after the objects has been destroyed
    delete p1;
}