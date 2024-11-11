#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include <memory>

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
    std::unique_ptr<pImpl> p_to_struct{}; // Using a smart pointer
    // pImpl *p_to_struct{nullptr};          // Using a raw pointer
};

#endif