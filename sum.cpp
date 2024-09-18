#include <iostream>

/* Function prototype */
int sum(int num1, int num2);

/* Main function */
int main(void)
{
    // Variable declaration
    int num1{5};
    int num2{10};
    std::cout << sum(num1, num2) << std::endl;
    return 0;
}

/* Function definition */
int sum(int num1, int num2)
{
    return num1 + num2;
}