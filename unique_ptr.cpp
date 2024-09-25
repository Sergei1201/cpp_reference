/* Introducing smart pointers in C++ */
// Example using a smart pointer for accessing member variables and member function of a given class
#include <iostream>
#include <string>
#include <memory>

class Person
{
private:
    // Member variables
    std::string m_firstName{};
    std::string m_lastName{};
    int m_age{};

public:
    // Constructor
    Person(std::string_view firstName, std::string_view lastName, int age)
        : m_firstName{firstName}, m_lastName{lastName}, m_age{age}
    {
        std::cout << "Constructor ran..." << std::endl;
    }
    // Destructor
    ~Person()
    {
        std::cout << "Destructor ran..." << std::endl;
    }
    // Member functions
    std::string greetings() const
    {
        return "Greetings " + m_firstName + " " + m_lastName + ". You are " + std::to_string(m_age);
    };
};

// Instantiate a new person object by dynamically allocating memory on the heap at runtime
int main(void)
{
    // 1. By manually allocating and deallocating memory for a new object
    // Person *p1{new (std::nothrow) Person{"Sergei", "Sokolov", 40}};
    // std::cout << p1->greetings() << std::endl;
    // delete p1;
    // p1 = nullptr;
    // 2. By using a smart pointer to automatically deallocate memory when it's not needed anymore
    // std::unique_ptr<Person> p1{std::unique_ptr<Person>(new (std::nothrow) Person{"Sergei", "Sokolov", 40})};
    // std::cout << p1->greetings() << std::endl;
    // // Here we do not have to manually deallocate memory after we've used the object
    // 3. By using a unique pointer with make_unique function without using new operator
    // std::unique_ptr<Person> p1{std::make_unique<Person>("Sergei", "Sokolov", 40)}; /* Do not have to
    // worry about deallocating memory as well, instead the compiler will do this job automatically */
    // 4. We can transfer the ownership of one pointer to another (without making copies)
    // Person *p{new (std::nothrow) Person{"Sergei", "Sokolov", 40}};
    std::unique_ptr<Person> p1{std::make_unique<Person>("Sergei", "Sokolov", 40)};
    std::unique_ptr<Person> p2{std::move(p1)};
    std::cout << p2->greetings() << std::endl;
    return 0;
}