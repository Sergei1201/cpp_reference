/* Structs in C++ */
#include <iostream>
#include <string>

struct Person
{
    std::string m_first_name{};
    std::string m_last_name{};
    int m_age{};
    Person(std::string first_name, std::string last_name, int age)
        : m_first_name{first_name}, m_last_name{last_name}, m_age{age}
    {
    }
};

/*Function definitions*/
// Operator << overloading
std::ostream &operator<<(std::ostream &os, const Person &obj)
{
    os << "Personal info: First Name - " << obj.m_first_name << " Last Name - " << obj.m_last_name << " Age - " << obj.m_age;
    return os;
}

int main(void)
{
    Person p1{"Sergei", "Sokolov", 40};
    std::cout << p1 << std::endl;
}