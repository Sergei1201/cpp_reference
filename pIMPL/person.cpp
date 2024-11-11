#include "person.hpp"
#include <iostream>

// Struct
struct Person::pImpl
{
    std::string m_first_name{};
    std::string m_last_name{};
};
// Constructor
Person::Person(std::string first_name, std::string last_name)
{
    // Allocate memory on the heap
    p_struct = new pImpl{};
    p_struct->m_first_name = first_name;
    p_struct->m_last_name = last_name;
};
// Destructor
Person::~Person()
{
    std::cout << "Destructor ran..." << std::endl;
    // Deallocate memory after the object is destroyed
    delete p_struct;
};
// Public member functions
std::string Person::getName() const
{
    return p_struct->m_first_name + " " + p_struct->m_last_name;
}
