/* Virtual functions in C++ */
#include <iostream>
#include <memory>

class Base
{
private:
public:
    Base()
    {
        std::cout << "The base constructor ran..." << std::endl;
    };
    virtual ~Base()
    {
        std::cout << "The base destructor ran..." << std::endl;
    }
    virtual std::string greetings() const
    {
        return "Greetings from the base class";
    }
};
class Derived : public Base
{
private:
public:
    Derived()
    {
        std::cout << "The derived constructor ran..." << std::endl;
    }
    std::string greetings() const override
    {
        return "Greetings from the derived class";
    }
    ~Derived()
    {
        std::cout << "The derived destructor ran..." << std::endl;
    }
};

int main(void)
{
    Derived derived;
    Base *base{&derived};
    std::cout << base->greetings() << std::endl;
    // Base *base{new (std::nothrow) Derived};
    // std::cout << base->greetings() << std::endl;
    // delete base;
    return 0;
}