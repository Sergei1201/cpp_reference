/* Passing C-style array to function */
#include <iostream>
#include <string>

void printArray(int array[], size_t size);

int main(void)
{
    int array[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t size{sizeof(array) / sizeof(array[0])};
    printArray(array, size); // Should result in decaying of the array to a pointer
    return 0;
}

void printArray(int array[], size_t size)
{
    for (size_t i{0}; i < size; i++)
    {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
}