/* Implementation file */
#include <iostream>
#include <string>
#include "person.hpp"
class Person
{
private:
    std::string m_firstName{};
    std::string m_lastName{};
    int m_age{};

public:
    Person(std::string_view firstName, std::string_view lastName, int age)
        : m_firstName{firstName}, m_lastName{lastName}, m_age{age}
    {
    }
    std::string greetings() const
    {
        return "Greetings " + m_firstName + " " + m_lastName + ". You are " + std::to_string(m_age);
    }
};