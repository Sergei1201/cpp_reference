/* Operator overloading in C++ in object-oriented fashion */
#include <iostream>

class Vector
{
    // Member variables
private:
    int m_x{};
    int m_y{};
    int m_z{};

public:
    // Public default constructor
    Vector() = default;
    // Parameterized constructor
    Vector(int x, int y, int z)
        : m_x{x}, m_y{y}, m_z{z}
    {
    }
    // Overloading + operator
    Vector operator+(const Vector &rhs) const
    {
        Vector result{};
        result.m_x = m_x + rhs.m_x;
        result.m_y = m_y + rhs.m_y;
        result.m_z = m_z + rhs.m_z;
        return result;
    }
    // Overloading the increment operator (++)
    Vector &operator++()
    {
        m_x = m_x + 1;
        m_y = m_y + 1;
        m_z = m_z + 1;
        return *this;
    }
    // Overloading the equality operator (bool) (use friend function to access the private members of the class)
    friend bool operator==(const Vector &lhs, const Vector &rhs);
    // Overloading std::cout operator (use friend funcion in order to access the private members of the class)
    friend std::ostream &operator<<(std::ostream &out, const Vector &obj);
};
// Overloading the equality operator (function definition)
bool operator==(const Vector &lhs, const Vector &rhs)
{
    // Just make a simple comparison between two objects that are passed in here
    if (lhs.m_x == rhs.m_x && lhs.m_y == rhs.m_y && lhs.m_z == rhs.m_z)
    {
        return true;
    }
    else
    {
        return false;
    };
}
// Overloading the cout operator (function implementation)
std::ostream &operator<<(std::ostream &out, const Vector &obj)
{
    out << "The object: X: " << obj.m_x << " Y: " << obj.m_y << " Z: " << obj.m_z << std::endl;
    return out;
}

int main(void)
{
    // Instantiate objects from the class
    // Vector v1{2, 3, 5};
    // Vector v2{6, 7, 8};
    // v1 = v1 + v2;
    // // Overloading the plus operator (when adding two objects together)
    // std::cout << "X: " << v1.m_x << " Y: " << v1.m_y << " Z: " << v1.m_z << std::endl;
    // // Overloading ++ operator (incrementing an object)
    // Vector v3{10, 11, 12};
    // ++v3;
    // std::cout << "X: " << v3.m_x << " Y: " << v3.m_y << " Z: " << v3.m_z << std::endl;
    Vector v5{1, 2, 3};
    Vector v6{1, 3, 3};
    if (v5 == v6)
    {
        std::cout << "The objects are equal" << std::endl;
    }
    else
    {
        std::cout << "The objects are not equal" << std::endl;
    }
    Vector v7{10, 15, 25};
    std::cout << v7;
    return 0;
}