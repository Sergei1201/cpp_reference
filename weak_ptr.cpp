/* Using weak pointers in C++ */
#include <iostream>
#include <string>
#include <memory>

class Person
{
private:
    // Private member variables (properties)
    std::string m_first_name{};
    std::string m_last_name{};
    int m_age{};

public:
    // Public constructor
    Person(std::string_view first_name, std::string_view last_name, int age)
        : m_first_name{first_name}, m_last_name{last_name}, m_age{age}
    {
        std::cout << "Constructor ran..." << std::endl;
    }
    // Public destructor
    ~Person()
    {
        std::cout << "Destructor ran... " << std::endl;
    }
    // Public member functions
    std::string greetings() const
    {
        return "Greetings " + m_first_name + " " + m_last_name + ". You are " + std::to_string(m_age);
    }
};

int main(void)
{
    // Let's recall the usage of shared pointers when working with objects
    // std::shared_ptr<Person> p1{std::make_shared<Person>("Sergei", "Sokolov", 40)}; // allocate memory on the heap for a new object
    // std::cout << p1->greetings() << std::endl;
    // // Let's share the pointer
    // {
    //     std::shared_ptr<Person> p2{p1};
    //     std::cout << p2->greetings() << std::endl;
    // }

    // std::cout << "Count number of pointers: " << p1.use_count() << std::endl;

    // Weak pointers
    std::shared_ptr<Person> p1{std::make_shared<Person>("Sergei", "Sokolov", 40)};
    std::cout << p1->greetings() << std::endl;
    // A weak pointer does not count the number of references and after deleting the block of memory, the pointer is pointing to, there's going to be a dangling pointer
    std::weak_ptr<Person> p2{p1};
    std::cout << "The number of references: " << p2.use_count() << std::endl;
    std::cout << "Is the weak pointer that points to the object valid? " << p2.expired() << std::endl;
    return 0;
}