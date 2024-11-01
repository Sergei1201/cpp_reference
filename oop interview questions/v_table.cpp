/* V_tables */
#include <iostream>
#include <vector>
#include <memory>

// Abstact class/interface
class Base
{
public:
    virtual ~Base() = default;
    virtual std::string sayHello() const = 0; // Pure virtual function, must be implemented in a derived class
    virtual std::string sayGoodbye() const = 0;
};

// Inheritance
class Derived1 : public Base
{
public:
    ~Derived1()
    {
        std::cout << "Derived 1 destructor ran..." << std::endl;
    }
    std::string sayHello() const override
    {
        return "Hello from Derived 1";
    }
    std::string sayGoodbye() const override
    {
        return "Goodbye from Derived 1";
    }
};
class Derived2 : public Base
{
public:
    ~Derived2()
    {
        std::cout << "Derived 2 destructor ran..." << std::endl;
    }
    std::string sayHello() const override
    {
        return "Hello from Derived 2";
    }
    std::string sayGoodbye() const override
    {
        return "Goodbye from Derived 2";
    }
};

int main(void)
{

    Base *p1{new Derived1};
    Base *p2{new Derived2};
    std::vector<Base *> v{};
    v.push_back(p1);
    v.push_back(p2);
    for (auto &derived : v)
    {
        std::cout << derived->sayHello() << std::endl;
        std::cout << derived->sayGoodbye() << std::endl;
    }
    delete p1;
    delete p2;

    return 0;
}
