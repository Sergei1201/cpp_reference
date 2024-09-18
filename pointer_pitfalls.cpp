/* Possible pointer pitfalls in C++ */
#include <iostream>
#include <string>
#include <memory>

int main(void)
{
    //     int *ptr{nullptr};
    //     *ptr = 50;
    //     std::cout << *ptr << std::endl;
    size_t size{50};
    // Dynamic memory allocation on the heap at runtime for an array of the size of "size"
    int *ptr(new (std::nothrow) int[size]{});
    // Check if the memory has been allocated successfully
    if (ptr == nullptr)
    {
        std::cout << "The memory hasn't been allocated";
        return (-1);
    }
    else
    {
        std::cout << "The memory of size " << size << " has been allocated " << std::endl;
    }
    // Fill the array with some data
    for (size_t i{0}; i < size; i++)
    {
        ptr[i] = i * 2;
    }
    // Print elements of the array
    for (size_t j{0}; j < size; j++)
    {
        std::cout << ptr[j] << "\t";
    }
    std::cout << std::endl;
    // Deallocate memory (give it back to the OS)
    delete[] ptr;
    // Set the pointer to null to avoid having dangling pointers

    return 0;
}
