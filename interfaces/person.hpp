/* Working with header files in C++  - an interface */
#include <iostream>
#include <string>
#ifndef PERSON_HPP
#define PERSON_HPP
class Person
{
    // Private member variables
private:
    std::string m_firstName{};
    std::string m_lastName{};
    int m_age{};
    // Public members of the class
public:
    Person(std::string_view firstName, std::string_view lastName, int age)
        : m_firstName{firstName}, m_lastName{lastName}, m_age{age}
    {
    }
    // Public member function
    std::string greetings() const
    {
        return "Greetings " + m_firstName + " " + m_lastName + ". You are " + std::to_string(m_age);
    }
};
#endif