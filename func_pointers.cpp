/* Function pointers in C++ */
#include <iostream>
#include <string>

/* Function forward declaration */
int add(int x, int y);

int multiply(int x, int y);

/* Main function */
int main(void)
{
    int x{};
    int y{};
    int op{};
    // Function pointer to point to a specific function at runtime
    int (*ptr)(int, int);
    std::cout << "Enter first number: ";
    std::cin >> x;
    std::cout << "Enter second number: ";
    std::cin >> y;
    do
    {
        std::cout << "Enter 1 for addition, 2 - for multiplication: ";
        std::cin >> op;
    } while (op < 1 || op > 2);

    if (op == 1)
    {
        ptr = add;
    }
    else if (op == 2)
    {
        ptr = multiply;
    }

    std::cout << ptr(x, y) << std::endl;
    return 0;
}

/* Function definition */
int add(int x, int y)
{
    return x + y;
}

int multiply(int x, int y)
{
    return x * y;
}