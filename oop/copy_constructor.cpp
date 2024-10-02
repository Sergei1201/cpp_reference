/* Using copy assignment, copy constructor, copy destructor in C++ */
#include <iostream>

class Array
{
    // Private members
private:
    int *data{};
    const size_t size{10};
    // Public members
public:
    // Regular constructor
    Array()
    {
        std::cout << "Constructor ran.." << std::endl;
        // Dynamically allocating memory in the heap for an array of integers when an object is being created
        data = new int[size];
    }
    // Custom copy constructor for creating a deep copy of an object with its own unique memory location
    // This copy constructor runs when a copy assignments is made
    Array(const Array &copyArray)
    {
        std::cout << "Copy constructor ran..." << std::endl;
        data = new int[size];
        for (size_t i{0}; i < size; i++)
        {
            data[i] = copyArray.data[i];
        }
    }
    // Destructor
    ~Array()
    {
        std::cout << "Destructor ran..." << std::endl;
        // Returning memory back to the operating system after an object has been destroyed
        delete[] data;
    }
    /* Member functions */
    // Fill array with some elements
    void fillArray()
    {
        for (size_t i{0}; i < size; i++)
        {
            data[i] = i * 2;
        }
    }
    // Set elements of the array
    void setArrayElements(int index, int arrData)
    {
        data[index] = arrData;
    }
    // Print elements of the array
    void printArray()
    {
        for (size_t i{0}; i < size; i++)
        {
            std::cout << data[i] << "\t";
        }
        std::cout << std::endl;
    }
};

int main(void)
{
    // Instantiate the Array class
    Array array1;
    // Fill our array
    array1.fillArray();
    // Set elements of the array
    array1.setArrayElements(0, 250);
    array1.printArray();
    // Copy assignment of the class (shallow copying with the same memory address of the first object)
    Array array2 = array1;
    array2.printArray();
    // Make sure all the memory has been returned back to the OS after the objects have been destroyed (the destructor runs)
    return 0;
}