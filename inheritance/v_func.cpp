/* Virtual functions in C++ */
#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base constructor ran..." << std::endl;
    }
    virtual ~Base()
    {
        std::cout << "Base destructor ran..." << std::endl;
    }
    virtual const std::string greetings() const
    {
        return "Greetings from the Base class";
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
    const std::string greetings() const override
    {
        return "Greetings from the Derived class";
    }
};

int main(void)
{
    Base *base{new Derived{}};
    std::cout << base->greetings() << std::endl;
    delete base;
    return 0;
}