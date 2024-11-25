/* RAII and operator overloading in C++ */
#include <iostream>
#include <memory>
class Array
{
    // Private member variables
private:
    int *data{nullptr};
    const std::size_t size{5};

public:
    // Public member functions
    Array()
    {
        // Dynamically allocate memory on the heap when an object is being instantiated (for an array)
        data = new int[size]{};
    }
    ~Array()
    {
        // Deallocate memory (return it back to the OS) after the object has been destroyed so that there are no memory leaks left
        delete[] data;
    }
    // Fill out the array with some data
    void fillArray()
    {
        for (std::size_t i{0}; i < size; i++)
        {
            data[i] = i * 2;
        }
    }
    // Print the array
    void printArray()
    {
        for (std::size_t i{0}; i < size; i++)
        {
            std::cout << data[i] << "\t";
        }
        std::cout << std::endl;
    }
    // Overload the subscript [] operator
    int &operator[](std::size_t idx)
    {
        return data[idx];
    }
    const int &operator[](std::size_t idx) const
    {
        return data[idx];
    }
};

int main(void)
{
    // Instantiate a new object
    Array arr1; // While the object is created the memory is being allocated on the heap for an array
    // Overload the [] operator
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    arr1[3] = 4;
    arr1[4] = 5;
    // Print the array
    //  arr1.fillArray();
    arr1.printArray();
    // Instantiate another object by using smart pointers
    // std::unique_ptr<Array> arr2{std::make_unique<Array>()};
    // arr2->fillArray();
    // arr2->printArray();
    // Make sure the memory has been returned back to the OS after we're done and the object has been destroyed
    return 0;
}