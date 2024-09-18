#include <iostream>
#include <string>

void greetings(std::string fullName, int age);

int main(void)
{
    std::string fullName{};
    int age{};
    std::cout << "Enter your full name please ";
    std::getline(std::cin, fullName);
    std::cout << "Enter your age please ";
    std::cin >> age;
    greetings(fullName, age);
    std::cerr << "There's something wrong with this program, isn't there?" << std::endl;
    return 0;
}

void greetings(std::string fullName, int age)
{
    std::cout << "Greetings to you " << fullName << " You are " << age << " years old" << std::endl;
}