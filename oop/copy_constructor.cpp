/* Using copy constructor, copy destructor, copy assignment in C++ */
#include <iostream>

class Array
{
    // Private members
private:
    int *data{};
    const size_t size{5};

public:
    // Public members
    Array()
    {
        // Allocate memory in the heap dynamically for the array when an object is being created
        data = new int[size]{};
    }
    // Deallocate memory (return it back to the operating system) after the object is destroyed
    ~Array()
    {
        delete[] data;
    }
    // Fill out the array with some values
    void fillArray()
    {
        for (int i = 0; i < size; i++)
        {
            data[i] = i * 2;
        }
    }
    // Print out the array
    void printArray()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << data[i] << "\t";
        }
        std::cout << std::endl;
    }
};

int main(void)
{
    // Instantiate our class
    Array array;
    // Fill our array with some elements
    array.fillArray();
    // Print the elements of the array
    array.printArray();
    // After the object is destroyed the memory should be released back to the OS when destructor starts working
}