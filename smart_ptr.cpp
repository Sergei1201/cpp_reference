/* Smart pointers in C++ */
#include <iostream>
#include <memory>

class Example
{
public:
    Example()
    {
        std::cout << "The constructor of the base class ran..." << std::endl;
    }
    ~Example()
    {
        std::cout << "The destructor of the base class ran... " << std::endl;
    }
};

int main()
{
    // Creating a unique pointer to dynamically allocate memory on the heap for a new object (no need to manually deallocate memory after the object has been destroyed)
    std::unique_ptr<Example> example{std::unique_ptr<Example>(new (std::nothrow) Example{})};
    // Instantiate a new example object
    // Example example;
    return 0;
}