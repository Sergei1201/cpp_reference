/* Header file in C++ - prototype our class */
#include <iostream>
#include <memory>
#ifndef PERSON_H
#define PERSON_H

class Person
{
    // Private member variables for initializing an object
private:
    std::string m_firstName{};
    std::string m_lastName{};
    int m_age{};

public:
    // Public constructor
    Person(std::string_view firstName, std::string_view lastName, int age);
    // Public member functions (greetings)
    std::string greetings() const;
};

#endif