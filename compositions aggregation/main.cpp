/* Composition & aggregation in C++ classes */
#include <iostream>
struct Engine
{

    std::string make{};
    int capacity{};
};

class Car
{
private:
    std::string m_model{};
    std::string m_color{};

public:
    Car(std::string model, std::string color, const Engine &e)
        : m_model{model}, m_color{color}
    {
        std::cout << "The car has the engine: " << e.make << " with the capacity of " << e.capacity << " horse powers" << std::endl;
    }
};

int main(void)
{
    Engine e{"Turbine", 200};
    Car c1{"BMW", "blue", e};
    return 0;
}