/* Constructor order in C++ */
#include <iostream>

class A
{
private:
    std::string m_name{};

public:
    A()
    {
        std::cout << "A constructor ran..." << std::endl;
    }
    A(std::string name)
    {
        std::cout << "The parameterized A constructor ran..." << std::endl;
    }
};
class B : public A
{
private:
    std::string m_firstName{};

public:
    B()
    {
        std::cout << "B constructor ran..." << std::endl;
    }
    B(std::string firstName)
        : A(firstName)
    {
        std::cout << "The parameterized B constructor ran..." << std::endl;
    }
};
class C : public B
{
public:
    C()
    {
        std::cout << "C constructor ran..." << std::endl;
    }
    C(std::string name)
        : B(name)
    {
        std::cout << "The parameterized C constructor ran..." << std::endl;
    }
};

int main(void)
{
    // A a;
    // B b{"Sergei"};
    C c{"Sergei"};
    return 0;
}