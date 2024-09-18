/* Dynamic memory allocation in C++ using C-style arrays */
#include <iostream>
#include <string>
#include <memory>

int main(void)
{
    // Size of the array
    size_t size{};
    std::cout << "Enter the size of the array for dynamic memory allocation on the heap during runtime ";
    std::cin >> size;
    // Dynamic memory allocation for an array of the size integers
    int *ptr{new (std::nothrow) int[size]};
    // Make sure that the memory has been allocated successfully
    if (ptr == nullptr)
    {
        std::cout << "The memory has not been allocated" << std::endl;
        return (-1);
    }
    else
    {
        std::cout << "The memory for the array of " << size << " elements has been allocated" << std::endl;
    }
    // Fill the brand new array with some values
    for (size_t i{0}; i < size; i++)
    {
        ptr[i] = i * 2;
    }
    // Print the array
    for (size_t j{0}; j < size; j++)
    {
        std::cout << ptr[j] << "\t";
    }
    std::cout << std::endl;
    // Deallocate memory after using it
    delete[] ptr;
    // Point the pointer to null explicitly so that there's no dangling pointer left in the memory
    ptr = nullptr;
    return 0;
}