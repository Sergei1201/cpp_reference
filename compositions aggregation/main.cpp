/* Composition & aggregation in C++ classes */
#include <iostream>
struct Engine
{
    std::string type{};
    int capacity{};
};

class Car
{
private:
    std::string m_model{};
    std::string m_color{};
    Engine m_engine{};

public:
    Car(std::string model, std::string color, const Engine &e)
        : m_model{model}, m_color{color}, m_engine{e}
    {
    }
    ~Car() {}
    friend std::ostream &operator<<(std::ostream &os, const Car &obj);
};
// Overload << operator
std::ostream &operator<<(std::ostream &os, const Car &obj)
{
    os << "The car's parameters: model " << obj.m_model << ", color " << obj.m_color << ", engine's type " << obj.m_engine.type << ", engine's capacity " << obj.m_engine.capacity;
    return os;
};

int main(void)
{
    Engine e{"Turbine", 200};
    Car c1{"BMW", "blue", e};
    std::cout << c1 << std::endl;
    return 0;
}