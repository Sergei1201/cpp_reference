#include "person.hpp"
#include <string>
#include <string_view>

Person::Person(std::string_view firstName, std::string_view lastName, int age)
    : m_firstName{firstName}, m_lastName{lastName}, m_age{age}
{
}
std::string Person::greetings() const
{
    return "Greetings " + m_firstName + " " + m_lastName + ". You are " + std::to_string(m_age);
}
