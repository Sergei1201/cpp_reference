#include <iostream>
#include <vector>
#include <string>

/* Function prototyping */
// For loop function to print elements of an array (C-style array)
// void printArray(int arr[], int size);

// /* Main function */
// int main(void)
// {
//     int arr1[]{1, 2, 2, 3, 4, 22, 222, -5};
//     int size = sizeof(arr1) / sizeof(arr1[0]);
//     printArray(arr1, size);
//     return 0;
// }

// /* Function definition */
// void printArray(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         std::cout << arr[i] << '\t';
//     }
// }

// Print elements of a given array using while loop (C-style array)
// void printArray(int arr[], int size);

// int main(void)
// {
//     int arr1[]{10, -5, 3, 2, 1};
//     int size{sizeof(arr1) / sizeof(arr1[0])};
//     printArray(arr1, size);
//     return 0;
// }

// void printArray(int arr[], int size)
// {
//     int i{0};
//     while (i < size)
//     {
//         std::cout << arr[i] << '\t';
//         i++;
//     }
//     std::cout << std::endl;
// }

/* Print elements of a given array using do-while loop (C-style array) */
// void printArray(int arr[], int size);

// int main(void)
// {
//     int arr1[]{1, 2, 3, 3, 4, 4, 4, 4, 0};
//     int size{sizeof(arr1) / sizeof(arr1[0])};
//     printArray(arr1, size);
//     return 0;
// }

// void printArray(int arr[], int size)
// {
//     int i{0};
//     do
//     {
//         std::cout << arr[i] << '\t';
//         i++;
//     } while (i < size);
//     std::cout << std::endl;
// }

/* Print all the elements of a given vector - more flexible type of an array which knows its size beforehand */
// void printArray(std::vector<int> v);

// int main(void)
// {
//     std::vector<int> v{5, 6, 7, 1, 0, 2};
//     // We do not need to pass the size of the vector since the vector is smart enough to figure out its size by itself. So we just invoke the printArray function with give arguments
//     printArray(v);
//     return 0;
// }

// void printArray(std::vector<int> v)
// {
//     // Print all the elements of a vector using an enhanced for loop
//     for (auto element : v)
//     {
//         std::cout << element << '\t';
//     }
//     std::cout << std::endl;
// }

/* Using size_t to represent positive numbers in a loop */
// void printArray(int arr[], int size);

// int main(void)
// {
//     int arr1[]{1, 2, 3, 4, 4, 55, 66, 79};
//     int size{sizeof(arr1) / sizeof(arr1[0])};
//     printArray(arr1, size);
//     return 0;
// }

// void printArray(int arr[], int size)
// {
//     for (size_t i{0}; i < size; i++)
//     {
//         std::cout << arr[i] << '\t';
//     }
//     std::cout << std::endl;
// }

/* Using size_t type to represent the size (positive) in a loop (for example, while loop) */
void printArray(int arr[], int size);

int main(void)
{
    int arr1[]{1, 2, 3, 4, 1, 11, 22, 33};
    int size{sizeof(arr1) / sizeof(arr1[0])};
    printArray(arr1, size);
    return 0;
}

void printArray(int arr[], int size)
{
    size_t i{0};
    while (i < size)
    {
        std::cout << arr[i] << '\t';
        i++;
    }
    std::cout << std::endl;
}