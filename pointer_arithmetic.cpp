/* Pointer arithmetic in C++ */
#include <iostream>
#include <string>
#include <vector>

/* Forward declaration */
void printArray(int array[], int size);

int main(void)
{
    int array[]{1, 2, 3, 4, 5, 8, 10, 25};
    int *ptr{array};
    std::vector<int> v{0, 1, 2, 3, 4};
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    std::cout << "The size of the vector: " << sizeof(v) << std::endl;
    std::cout << "The number of elements of the vector: " << std::size(v) << std::endl;
    int size{sizeof(array) / sizeof(array[0])};
    std::cout << ptr << std::endl;
    printArray(array, size);
    return 0;
}

/* Function definition */
void printArray(int array[], int size)
{
    for (size_t i{0}; i < size; i++)
    {
        std::cout << (array + i) << "\t";
    }
    std::cout << std::endl;
}