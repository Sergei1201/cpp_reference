// /* Working with two-dimensional C-style arrays in C++ */
// #include <iostream>
// #include <vector>
// #include <string>

// /* Global variables */
// const size_t r{5};
// const size_t c{3};

// /* Function prototype */
// void printArray(int arr[r][c]);

// /* Main function */
// int main(void)
// {
//     int arr1[r][c]{
//         {1, 2, 3},
//         {5, 6, 7},
//         {10, 11, 12},
//         {33, 22, 99},
//         {99, 100, 150}};
//     printArray(arr1);
//     return 0;
// }

// /* Function definition*/
// void printArray(int arr[r][c])
// {
//     for (size_t i{0}; i < r; i++)
//     {
//         for (size_t j{0}; j < c; j++)
//         {
//             std::cout << arr[i][j] << '\t';
//         }
//         std::cout << std::endl;
//     }
//     std::cout << std::endl;
// }

/* Array bounds in C++ */
#include <iostream>
#include <vector>
#include <string>
void printArray(int arr[], int size);

int main(void)
{
    int arr1[]{5, 1, 11, 120, 90};
    int size{sizeof(arr1) / sizeof(arr1[0])};
    printArray(arr1, size);
    // Accessing a garbage value of the C-style array
    std::cout << arr1[7] << std::endl;
    return 0;
}

void printArray(int arr[], int size)
{
    for (size_t i{0}; i < size; i++)
    {
        std::cout << arr[i] << '\t';
    }
    std::cout << std::endl;
}