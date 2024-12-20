#include "person.hpp"
#include <iostream>
#include <memory>

// Struct
struct Person::pImpl
{
    // All members are public by default in a struct
    std::string m_first_name{};
    std::string m_last_name{};
};

// Constructor
Person::Person(std::string first_name, std::string last_name)
{
    std::cout << "Constructor ran..." << std::endl;
    // Dynamic memory allocation for a struct on the heap when an object is being constructed from the class
    // p_to_struct = new pImpl{}; // Using a raw pointer
    p_to_struct = std::make_unique<pImpl>(); // Using a smart pointer
    p_to_struct->m_first_name = first_name;
    p_to_struct->m_last_name = last_name;
};
// Destructor
Person::~Person()
{
    std::cout << "Destructor ran..." << std::endl;
    // Free memory and return it back to the OS after the objec has been destroyed (manually when using a raw pointer)
    // delete p_to_struct; // Automatic memory releasing when using a smart pointer
};
// Member functions
std::string Person::getName() const
{
    return p_to_struct->m_first_name + " " + p_to_struct->m_last_name;
}