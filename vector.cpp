/* Passing array to function as arguments using vectors in C++ */
#include <iostream>
#include <vector>
#include <string>

/* Function forward declaration */
void printArray(const std::vector<int> &v);

/* Main function */
int main(void)
{
    std::vector<int> v{1, 2, 3, 4, 5};
    v.push_back(10);
    v.push_back(20);
    // Print the array through the function (passed by reference)
    printArray(v);
    // Print the original array so that we can see if it's been modified
    std::cout << "The original array: " << std::endl;
    for (auto el : v)
    {
        std::cout << el << "\t";
    }
    std::cout << std::endl;

    return 0;
}

/* Function definition */
void printArray(const std::vector<int> &v)
{
    for (auto element : v)
    {
        std::cout << element << "\t";
    }
    std::cout << std::endl;
}