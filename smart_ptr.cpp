/* Smart pointers in C++ */
#include <iostream>
#include <memory>
#include <string>

class Example
{
private:
    std::string m_firstName{};
    std::string m_lastName{};

public:
    Example(std::string_view firstName, std::string_view lastName)
        : m_firstName{firstName}, m_lastName{lastName}
    {
        std::cout << "The constructor of the base class ran..." << std::endl;
    }
    ~Example()
    {
        std::cout << "The destructor of the base class ran... " << std::endl;
    }
    const std::string sayHello()
    {
        return "Hello " + m_firstName + " " + m_lastName;
    }
};

int main()
{
    // Creating a unique pointer to dynamically allocate memory on the heap for a new object (no need to manually deallocate memory after the object has been destroyed)
    // Example *pointer{new (std::nothrow) Example{}};
    // std::unique_ptr<Example> example{std::unique_ptr<Example>(new (std::nothrow) Example{})};
    // Dynamically allocating an array of objects using smart pointers
    std::unique_ptr<Example> example{std::make_unique<Example>("Sergei", "Sokolov")};
    std::cout << example->sayHello() << std::endl;
    //  Instantiate a new example object
    //  Example example;
    return 0;
}