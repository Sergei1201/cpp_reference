/* Shared pointers in C++ */
#include <iostream>
#include <memory>
#include <string>

class Person
{
private:
    // Member variables (properties)
    std::string m_firstName{};
    std::string m_lastName{};
    int m_age{};

public:
    // Public constructor
    Person(std::string_view firstName, std::string_view lastName, int age)
        : m_firstName{firstName}, m_lastName{lastName}, m_age(age)
    {
        std::cout << "Constructor ran..." << std::endl;
    }
    // Public destructor
    ~Person()
    {
        std::cout << "Destructor ran..." << std::endl;
    }
    // Public member functions
    std::string greetings() const
    {
        return "Greetings " + m_firstName + " " + m_lastName + ". You are " + std::to_string(m_age);
    }
};

int main(void)
{
    // Create an object by using a shared pointer (without having to use new and delete)
    std::shared_ptr<Person> p{std::make_shared<Person>("Sergei", "Sokolov", 40)}; // heap allocated
    // Now let's create another pointer and make it point to the first one (remember that unique pointer doesn't allow that (sharing, only transferring the ownership))
    {
        std::shared_ptr<Person> p2{p};
        std::cout << p->greetings() << std::endl;
        std::cout << p2->greetings() << std::endl;
    }

    // Use count of shared pointers
    std::cout << "Use count of shared pointers: " << p.use_count() << std::endl;
}
