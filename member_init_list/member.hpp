/* Class prototype goes in here */
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

class Person
{
private:
    // Private class variables
    int m_age{};
    std::string m_first_name{};
    std::string m_last_name{};

public:
    // Default constructor
    Person() = default;
    // Regular constructor
    Person(int age, std::string first_name, std::string last_name);
    /* Member functions */
    const std::string greetings() const;
    /* Non-member functions */
    // Operator << overloading for an object representation
    friend std::ostream &operator<<(std::ostream &os, const Person &obj);
};

#endif