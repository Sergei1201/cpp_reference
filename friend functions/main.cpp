/* Example of implementing a friend function in C++ */
#include <iostream>

class Person
{
private:
    std::string m_first_name{};
    std::string m_last_name{};
    int m_age{};

public:
    // Using the explicit keyword will prevent the constructor from implicitly converting types by the compiler in order to make our code a little bit safer and more robust
    explicit Person(std::string firstName, std::string lastName, int age)
        : m_first_name{firstName}, m_last_name{lastName}, m_age{age}
    {
    }
    const std::string greetings() const
    {
        return "Greetings " + m_first_name + " " + m_last_name + ". You are " + std::to_string(m_age);
    }
    // Declare a friend function inside the class to access private members of the class
    friend std::ostream &operator<<(std::ostream &os, const Person &obj);
};
std::ostream &operator<<(std::ostream &os, const Person &obj)
{
    os << "Personal information on the object. First name: " << obj.m_first_name << ". Last name: " << obj.m_last_name << ". Age: " << obj.m_age;
    return os;
}

int main(void)
{
    // Instantiate the Person class
    Person p1{"Sergei", "Sokolov", 40};
    std::cout << p1 << std::endl;
    std::cout << p1.greetings() << std::endl;
    return 0;
}