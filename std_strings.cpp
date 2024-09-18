/* Functions in C++ */
#include <iostream>
#include <string>

/* Function prototyping */
std::string greetings(std::string firstName, std::string lastName);

int main(void)
{
    std::string firstName{};
    std::string lastName{};
    std::string fullName{};
    std::cout << "What's your first name? ";
    std::getline(std::cin, firstName);
    std::cout << "What's your last name? ";
    std::getline(std::cin, lastName);
    fullName = greetings(firstName, lastName);
    std::cout << fullName << std::endl;

    return 0;
}

/* Function definition */
std::string greetings(std::string firstName, std::string lastName)
{
    return "Greetings " + firstName + " " + lastName;
}