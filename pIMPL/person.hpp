#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>

class Person
{
public:
    // Constructor
    Person(std::string first_name, std::string last_name);
    // Destructor
    ~Person();
    std::string getName() const;

private:
    struct pImpl;
    pImpl *p_struct{nullptr};
};

#endif