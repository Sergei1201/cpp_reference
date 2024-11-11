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
    // Public member functions
    std::string getName() const;

private:
    // Private member variables
    // Pointer to implementation
    struct pImpl;
    pImpl *p_to_struct{nullptr};
};

#endif