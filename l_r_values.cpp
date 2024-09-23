/* lvalues and rvalues references in C++ */
#include <iostream>

int main(void)
{
    int x{10};
    int y{20};
    int &ref{x}; // ref is an lvalue referernce
    int &&r{25}; // rvalue reference
    const int &reference{15};
    std::cout << ref << std::endl;
    std::cout << reference << std::endl;
    std::cout << r << std::endl;
    return 0;
}