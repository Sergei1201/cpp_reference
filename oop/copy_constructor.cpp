/* Copy constructor, copy assignment operator, destructors in C++ */
#include <iostream>

class Array
{
    /* Private data members */

private:
    int *data{};
    const size_t size{10};

    /* Public constructor & member functions */

public:
    // Regular constructor
    Array()
    {
        std::cout << "Constructor ran..." << std::endl;
        // Dynamically allocate memory in the heap for an array of integers when an object is being constructed
        data = new int[size];
    }

    // Copy constructor to create a deep copy of an object (the constructor is invoked when we make a copy of an object) with its own memory location
    Array(const Array &rhs)
    {
        std::cout << "Copy constructor ran..." << std::endl;
        // Allocating memory for a new object dynamically in the heap before the object is created
        data = new int[size];
        // Copying data from the original object to the newly created object
        for (size_t i{0}; i < size; i++)
        {
            data[i] = rhs.data[i];
        }
    }

    // Copy assignment operator (is called when an object has already been constructed) for making copies of objects with their own memory location after the object has been created
    Array &operator=(const Array &rhs)
    {
        std::cout << "Copy assignment operator ran..." << std::endl;
        // Check if the object points to itself
        if (&rhs == this)
        {
            return *this;
        }
        // Deallocate memory before copy assignment
        if (this != nullptr)
            delete[] data;
        // Allocate memory dynamically in the heap for copy assignment
        data = new int[size];
        for (size_t i{0}; i < size; i++)
        {
            data[i] = rhs.data[i];
        }
        return *this;
    }

    // Destructor deallocates memory by returning it back to the operating system after objects have been destroyed
    ~Array()
    {
        std::cout << "Destructor ran..." << std::endl;
        delete[] data;
    }

    /* Public member functions */

    // Filling an array with some data
    void fillArray()
    {
        for (size_t i{0}; i < size; i++)
        {
            data[i] = i * 2;
        }
    }

    // Set elements of the array
    void setArray(int index, int arrData)
    {
        data[index] = arrData;
    }

    // Printing the array
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
    // Fill our array using member function
    array1.fillArray();
    // Set a new value to the array
    array1.setArray(0, 255);
    // Let's create another object by copying the elements of the first object into it
    // Without writing a custom copy constructor we'll get only a shallow copy of the object because
    // the memory will be shared with the first object. Let's see what's going to happen in this case
    // Print the elements of the array
    array1.printArray();
    Array array2;
    array2 = array1;
    // Array array2{array1};
    array2.printArray();
    // The memory used should be returned back to the OS after invoking the destructor (when objects are destroyed)
    return 0;
}