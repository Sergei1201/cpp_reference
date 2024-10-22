/* Order of constructors in C++ */
#include <iostream>

class A
{
private:
    std::string m_name{};

public:
    A()
    {
        std::cout << "Default A constructor ran..." << std::endl;
    }
    A(std::string name)
        : m_name{name}
    {
        std::cout << "Parameterized A constructor ran..." << std::endl;
    }
};
class B : public A
{
public:
    B()
    {
        std::cout << "Default B constructor ran..." << std::endl;
    }
    B(std::string name)
        : A(name)
    {
        std::cout << "Parameterized B constructor ran..." << std::endl;
    }
};
class C : public B
{
public:
    C()
    {
        std::cout << "Default C constructor ran..." << std::endl;
    }
    C(std::string name)
        : B{name}
    {
        std::cout << "Parameterized C constructor ran..." << std::endl;
    }
};

int main(void)
{
    A a{"Sergei"};
    B b{"Sergei"};
    C c{"Sergei"};
    std::cout << "Size of A: " << sizeof(A) << " Size of B: " << sizeof(B) << " Size of C: " << sizeof(C) << std::endl;
    return 0;
}