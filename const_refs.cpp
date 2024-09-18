/* References in C++ */
#include <iostream>
#include <string>

int main(void)
{
    int x{5};
    int y{10};
    int &ref{x};
    std::cout << "The variable is: " << x << std::endl;
    std::cout << "The reference to the variable is: " << ref << std::endl;
    std::cout << "The address of the variable is " << &x << std::endl;
    std::cout << "The address of the reference is " << &ref << std::endl;
    ref = y;
    std::cout << "The reference is now " << ref << std::endl;
    std::cout << "The variable is now " << x << std::endl;

    return 0;
}