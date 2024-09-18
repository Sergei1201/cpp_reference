/* Vectors in C++ */
#include <vector>
#include <iostream>
#include <string>

/* Function prototyping */
void printVector(std::vector<int> v);

/* Main */
int main(void)
{
    // Variable declaration and initialization goes here
    std::vector<int> v{5, 10, 12, 25};
    int element{};
    // Print the initial vector onto the screen
    printVector(v);
    // Add some new elements to the vector
    v.push_back(30);
    v.push_back(50);
    v.push_back(60);
    // Print the modified vector
    printVector(v);
    return 0;
}

/* Function definition */
void printVector(std::vector<int> v)
{
    // Print vector using enhanced for loop
    for (auto element : v)
    {
        std::cout << element << "\t";
    }
    std::cout << std::endl;
}