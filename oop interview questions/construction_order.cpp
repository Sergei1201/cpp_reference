/* Construction order */
#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base constructor ran..." << std::endl;
    };
    ~Base()
    {
        std::cout << "Base destructor ran..." << std::endl;
    }
};
class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived constructor ran..." << std::endl;
    }
    ~Derived()
    {
        std::cout << "Derived destructor ran..." << std::endl;
    }
};

int main(void)
{
    Derived d1;
    // Which order will be used to instantiate the d1 object
    // 1. Memory allocation enough for both Derived and Base classes
    // 2. Base constructor should be invoked
    // 3. Derived constructor is invoked and the d1 object is being instantiated
    // Destructors work in the opposite order:
    // 1. The derived portion of the d1 is destroyed
    // 2. The base class portion of the derived is destroyed
    return 0;
}