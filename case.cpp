#include <iostream>
#include <string>

int main(void)
{
    int color{};
    int age{};
    bool canHaveDrink{};
    std::string answer{};
    // std::cout << "Enter a number from 1 to 5 ";
    // std::cin >> color;

    /* if-else*/

    // if (color == "red")
    // {
    //     std::cout << "The color is red" << std::endl;
    // }
    // else if (color == "blue")
    // {
    //     std::cout << "The color is blue" << std::endl;
    // }
    // else if (color == "white")
    // {
    //     std::cout << "The color is white" << std::endl;
    // }
    // else
    // {
    //     std::cout << "You haven't chosen the color" << std::endl;
    // }
    // return 0;

    /* case */
    // switch (color)
    // {
    // case 1:
    //     std::cout << "The color is blue" << std::endl;
    //     break;
    // case 2:
    //     std::cout << "The color is red" << std::endl;
    //     break;
    // case 3:
    //     std::cout << "The color is green" << std::endl;
    //     break;
    // case 4:
    //     std::cout << "The color is white" << std::endl;
    //     break;
    // case 5:
    //     std::cout << "The color is black" << std::endl;
    //     break;
    // default:
    //     std::cout << "You haven't chosen the color" << std::endl;
    // }

    /* Logical operators */
    // std::cout << "Enter your age ";
    // std::cin >> age;
    // if (age >= 21 && age <= 80)
    // {
    //     std::cout << "You can have a drink" << std::endl;
    // }
    // else if (age < 21)
    // {
    //     std::cout << "You're a little bit too young to have a drink" << std::endl;
    // }
    // else
    // {
    //     std::cout << "Sorry, no drink for you, sir" << std::endl;
    // }

    /* Ternary operator in C++ */
    std::cout << "Enter your age please: ";
    std::cin >> age;
    answer = (age >= 21) ? "You can have a drink" : "Sorry, no drink available for you today";
    std::cout << answer << std::endl;
}