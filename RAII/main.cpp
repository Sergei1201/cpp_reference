/* RAII usage in C++ */
#include <iostream>

class Array
{
private:
    int *data{};
    const std::size_t size{5};

public:
    Array()
    {
        // Dynamically allocate memory for an array at runtime on the heap
        data = new int[size]{};
    }
    ~Array()
    {
        // Deallocate memory after an object has been destroyed
        delete[] data;
    }
    // Overloading the subscript [] operator
    int &operator[](std::size_t idx)
    {
        return data[idx];
    }
    const int &operator[](std::size_t idx) const
    {
        return data[idx];
    }
    // Print the elements of the array
    void printArray()
    {
        for (std::size_t i{0}; i < size; i++)
        {
            std::cout << data[i] << "\t";
        }
        std::cout << std::endl;
    }
};

int main(void)
{
    // Instantiate the class (create a new object)
    Array arr1; // At this moment the memory has been allocated on the heap for an array
    // Overload the subscript operator
    arr1[0] = 1;
    arr1[1] = 3;
    arr1[2] = 4;
    arr1[3] = 5;
    arr1[4] = 10;
    // Print the array
    arr1.printArray();
    // Make sure the memory has been returned back to the OS after the object has been destroyed (by using the valgrind tool)
    return 0;
}