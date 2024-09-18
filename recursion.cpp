/* Recursion in C++ */
#include <iostream>
#include <string>

/* Function forward declaration */
int countdown(int n);

int main(void)
{
    countdown(10);
    return 0;
}

/* Function definition */
int countdown(int n)
{
    // Base case where n = 0
    if (n == 0)
    {
        std::cout << "Blast off" << std::endl;
        return 0;
    }
    // Regular case, return the function recursively
    std::cout << n << std::endl;
    return countdown(n - 1);
}