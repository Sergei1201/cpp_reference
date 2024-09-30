#include <iostream>
#include <vector>
#include <memory>
#include "./person.hpp"

int main(int argc, char **argv)
{
    // 1. Creating a person object in the heap using new
    // Person *p1{new (std::nothrow) Person{"Sergei", "Sokolov", 40}};
    // std::cout << p1->greetings() << std::endl;
    // delete p1;
    // 2. Creating a new object by using a unique_ptr to automatically deallocate memory after we're finished with the object being used
    // std::unique_ptr<Person> p2{std::make_unique<Person>("Sergei", "Sokolov", 40)};
    // Make sure it's unique
    // std::unique_ptr<Person> p3{p2};
    // Make sure the memory has been automatically deallocated
    // 3. Creating a new objec in the heap using a shared pointer
    // std::shared_ptr<Person> p4{std::make_shared<Person>("Sergei", "Sokolov", 40)};
    // std::shared_ptr<Person> p5{p4};
    // std::cout << p4->greetings() << std::endl;
    // std::cout << "The link count: " << p4.use_count() << std::endl;
    // Make sure the memory has been deallocated as in the previous case
    // 4. Creating an object dynamically in the heap by using a weak_ptr which does not have link counts to its object
    // First we need to create a shared_ptr, then a weak_ptr
    std::shared_ptr<Person> p6{std::make_unique<Person>("Sergei", "Sokolov", 40)};
    std::weak_ptr<Person> p7{p6};
    std::cout << p6->greetings() << std::endl;
    std::cout << "The link count " << p6.use_count() << std::endl;
}