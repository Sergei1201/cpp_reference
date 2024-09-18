/* Basic class in C++ */
#include <iostream>
#include <vector>
#include <string>

/* Define base class */
class Person
{
private:
    // Private data members
    std::string m_firstName{};
    std::string m_lastName{};
    int m_age{};

public:
    // Constructor
    Person(std::string firstName, std::string lastName, int age)
        : m_firstName(firstName), m_lastName(lastName), m_age(age)
    {
    }
    /* Public member functions are defined here */
    // Setter member function
    void setAge(int age)
    {
        m_age = age;
    }
    // Getter member function (return by reference if the return operation might be expensive when returning by value)
    int &getAge(void)
    {
        return m_age;
    }
    std::string greetings(void)
    {
        return "Greetings " + m_firstName + " " + m_lastName + ". You are " + std::to_string(m_age) + " years old";
    }
};

/* Main function */
int main(void)
{
    // Instantiate the Person class
    Person p1{"Sergei", "Sokolov", 40};
    p1.setAge(45);
    p1.getAge();
    std::cout << p1.greetings() << std::endl;
    return 0;
}