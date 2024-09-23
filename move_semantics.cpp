/* Move semantics in C++ */
#include <iostream>

int main(void)
{
    std::string firstName{"Sergei"};
    std::string lastName{};

    // lastName = std::move(firstName); // stealing value using move semantics
    // lastName = static_cast<std::string &>(firstName); // Pass by reference
    lastName = static_cast<std::string &&>(firstName); // move

    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    return 0;
}