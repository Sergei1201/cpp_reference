/* Class implementation goes in here */
#include <iostream>
#include <string>
#include "member.hpp"

// Public constructor
Person::Person(int age, std::string first_name, std::string last_name)
    : m_age{age}, m_first_name{first_name}, m_last_name{last_name}
{
}
/* Public member functions */
// Greetings
const std::string Person::greetings() const
{
    return "Greetings " + m_first_name + " " + m_last_name + ". You are " + std::to_string(m_age);
}
/* Free (non-member) functions */
// Operator << overloading for an object representation
std::ostream &operator<<(std::ostream &os, const Person &obj)
{
    os << "Object info: first name " << obj.m_first_name << " last name " << obj.m_last_name << " age " << obj.m_age;
    return os;
}
