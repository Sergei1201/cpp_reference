/* A program for dynamic memory allocation for an array, printing elements of the array onto the screeen and deallocating the memory afterwards */
#include <iostream>
#include <string>

int main(void)
{
    // Dynamic memory allocation for an array of integers
    int *arr = new int[8];
    for (size_t i{0}; i < 8; i++)
    {
        arr[i] = 2 * i;
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
    // Deallocate memory after using it
    delete arr;
    arr = nullptr;
}
