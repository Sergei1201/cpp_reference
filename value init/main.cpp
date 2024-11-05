/* Value initialization in C++ */
#include <iostream>

struct Person
{
    Person()
        : firstName{"John"}, lastName{"Doe"}, x{10}, y{15}, p{nullptr}
    {
    }
    // Delegate constructor
    Person(int _x, int _y) : Person()
    {
        x = _x;
        y = _y;
    }
    std::string firstName{};
    std::string lastName{};
    int x{};
    int y{};
    int *p{nullptr};
};

int main(void)
{
    Person p1{30, 35};
    std::cout << p1.firstName << " " << p1.lastName << " " << p1.x << " " << p1.y << std::endl;
    return 0;
}