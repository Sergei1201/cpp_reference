/* Operator overloading in C++ */
#include <iostream>

class Vector
{
    // Member variables/data members
private:
    int m_x{};
    int m_y{};
    int m_z{};

public:
    // Default constructor
    Vector() = default;
    // Regular constructor
    Vector(int x, int y, int z)
        : m_x{x}, m_y{y}, m_z{z}
    {
    }
    /* Public member functions */

    // Overloading + operator (when adding two objects of the same class together)
    Vector operator+(const Vector &rhs) const
    {
        Vector result{};
        result.m_x = m_x + rhs.m_x;
        result.m_y = m_y + rhs.m_y;
        result.m_z = m_z + rhs.m_z;
        return result;
    }
    // Overloading the increment operator
    Vector &operator++()
    {
        m_x = m_x + 1;
        m_y = m_y + 1;
        m_z = m_z + 1;
        return *this;
    }
    // Overloading the cout operator (declaring a friend functing inside the class)
    friend std::ostream &operator<<(std::ostream &out, const Vector &v);
};
// Overloading the cout operator
std::ostream &operator<<(std::ostream &out, const Vector &v)
{
    out << "Vector: " << v.m_x << " " << v.m_y << " " << v.m_z;
    return out;
}

int main(void)
{
    // Instantiate class
    // Vector v1{2, 3, 4};
    // Vector v2{5, 6, 7};
    // // Overloading + operator
    // v1 = v1 + v2;
    // std::cout << "Overloading + operator: " << v1.m_x << " " << v1.m_y << " " << v1.m_z << std::endl;
    // // Overloading the increment operator
    // Vector v3{5, 10, 12};
    // ++v3;
    // std::cout << "Overloading the increment operator: " << v3.m_x << " " << v3.m_y << " " << v3.m_z << std::endl;
    Vector v4{5, 10, 15};
    std::cout << v4 << std::endl;
    return 0;
}