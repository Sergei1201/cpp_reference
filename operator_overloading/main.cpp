/* Operator overloading in C++ */
#include <iostream>

class Vector
{
    /* Member variables */
private:
    int m_x{};
    int m_y{};
    int m_z{};

public:
    /* Public member functions */
    // Default constructor
    Vector() = default;
    // Parametirized constructor
    Vector(int x, int y, int z)
        // Use member initialization list to initialize object
        : m_x{x}, m_y{y}, m_z{z}
    {
        // Empty body of the constructor
    }
    // Overload + operator
    Vector operator+(const Vector &rhs) const
    {
        Vector result{};
        result.m_x = m_x + rhs.m_x;
        result.m_y = m_y + rhs.m_y;
        result.m_z = m_z + rhs.m_z;
        return result;
    }
    // Overload ++ (prefix) operator
    Vector &operator++()
    {
        m_x = m_x + 1;
        m_y = m_y + 1;
        m_z = m_z + 1;
        return *this;
    }
    // Overload the comparison (==) operator
    friend bool operator==(const Vector &lhs, const Vector &rhs);
    // Overload the << operator
    friend std::ostream &operator<<(std::ostream &os, const Vector &obj);
};
// Overload the comparison (==) operator implementation
bool operator==(const Vector &lhs, const Vector &rhs)
{
    if (lhs.m_x == rhs.m_x && lhs.m_y == rhs.m_y && lhs.m_z == rhs.m_z)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Overload << operator implementation
std::ostream &operator<<(std::ostream &os, const Vector &obj)
{
    os << "The object representation: " << obj.m_x << " " << obj.m_y << " " << obj.m_z;
    return os;
}

int main(void)
{
    // Instantiate the class by creating an object
    // Vector v1{1, 2, 3};
    // Vector v2{2, 3, 4};
    // // Overload + operator
    // v1 = v1 + v2;
    // std::cout << "Overloading + operator: " << v1.m_x << " " << v1.m_y << " " << v1.m_z << std::endl;
    // // Overload ++ operator (prefix)
    // Vector v3{5, 10, 20};
    // ++v3;
    // std::cout << "Overloading ++ operator: " << v3.m_x << " " << v3.m_y << " " << v3.m_z << std::endl;
    Vector v4{10, 11, 12};
    Vector v5{10, 12, 12};
    if (v4 == v5)
    {
        std::cout << "The objects are equal" << std::endl;
    }
    else
    {
        std::cout << "The objects are not equal" << std::endl;
    }
    Vector v6{20, 25, 30};
    std::cout << v6 << std::endl;

    return 0;
}