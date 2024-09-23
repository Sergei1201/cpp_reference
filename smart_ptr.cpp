/* Smart pointers in C++ */
#include <iostream>

int main(void)
{
    int var{10};
    size_t size{100};
    // Dynamically allocate memory for an array of 100 integers on the heap (at runtime)
    int *array = new (std::nothrow) int[size]{};
    for (size_t i{0}; i < size; i++)
    {
        array[i] = i * 2;
    }
    int *pointer{array};
    int *ptr{&var};

    std::cout << "The pointer is pointer at the start of the dynamically alllocated array: " << pointer << std::endl;
    // std::cout << "The pointer points to the memory address of: " << ptr << std::endl;
    // std::cout << "The value at the addres pointer is pointing at is " << *ptr << std::endl;
    // std::cout << "The address of the variable is: " << &var << std::endl;
    delete[] array;
    // array = nullptr;
    return 0;
}