/* Delegate constructor in C++ */
#include <iostream>

class Person
{
private:
    // Private member variables (properties in other programming languages)
    std::string m_first_Name{};
    std::string m_last_Name{};
    int m_age{};
    int m_x{};
    int m_y{};

public:
    // Constructor
    Person()
        : m_first_Name{"Sergei"}, m_last_Name{"Sokolov"}, m_age{40}
    {
        std::cout << "Default constructor ran..." << std::endl;
    }
    // Delegate constructor is invoked here
    Person(int _x, int _y)
        : Person()
    {
        std::cout << "Parameterized constuctor ran..." << std::endl;
        m_x = _x;
        m_y = _y;
    }
    friend std::ostream &operator<<(std::ostream &os, const Person &obj);
};
std::ostream &operator<<(std::ostream &os, const Person &obj)
{
    os << "Person's information: " << obj.m_first_Name << " " << obj.m_last_Name << " " << obj.m_age;
    return os;
}

int main(void)
{
    Person p1{5, 10};
    std::cout << p1 << std::endl;

    return 0;
}