/* Operator overloading in C++ using classes */
#include <iostream>

class Vector
{
public:
    int m_x{};
    int m_y{};
    int m_z{};

public:
    // Constructor
    Vector(int x = 0, int y = 0, int z = 0)
        : m_x{x}, m_y{y}, m_z{z}

    {
    }
    Vector operator+(const Vector &rhs) const
    {
        Vector sum{};
        sum.m_x = m_x + rhs.m_x;
        sum.m_y = m_y + rhs.m_y;
        sum.m_z = m_z + rhs.m_z;
        return sum;
    }
};

int main(void)
{
    // Instantiate the classes
    Vector v1{1, 2, 3};
    Vector v2{4, 5, 6};
    v1 = v1 + v2;
    std::cout << "Result x: " << v1.m_x << " Result y: " << v1.m_y << " Result x: " << v1.m_z << std::endl;
}