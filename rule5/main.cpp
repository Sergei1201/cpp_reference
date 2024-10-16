/* The rule of 5 in C++ */
#include <iostream>

class Array
{
    // Private data members
private:
    const std::size_t size{10};
    int *data{nullptr};

public:
    /* Public member functions */

    // Regular constructor
    Array()
    {
        // Dynamically allocate memory on the heap during an object construction
        std::cout << "Constructor ran" << std::endl;
        data = new int[size]{};
    }
    // Regular destructor
    ~Array()
    {
        std::cout << "Destructor ran" << std::endl;
        // Deallocate memory after object has been destroyed
        delete[] data;
    }
    // Custom copy constructor is invoked when a copy of an object is being instantiated to make a deep copy of an object with its own memory location
    Array(const Array &obj)
    {
        std::cout << "Copy constructor ran" << std::endl;
        // Allocate memory dynamically for an array
        data = new int[size]{};
        // Fill the array with data from the original object in a for loop
        for (std::size_t i{0}; i < size; i++)
        {
            data[i] = obj.data[i];
        }
    }
    // Move constructor to transfer the ownership to another object
    Array(const Array &&obj)
    {
        // Allocate memory on the heap
        data = new int[size]{};
        std::cout << "Move constructor ran" << std::endl;
        for (std::size_t i{0}; i < size; i++)
        {
            data[i] = obj.data[i];
        }
    }
    // Copy assignment operator is invoked when a copy of an already constructed object is being made
    Array &operator=(const Array &obj)
    {
        std::cout << "Copy assignment operator is used" << std::endl;
        // Check if the object passed it is equal to the new object
        if (this == &obj)
        {
            // Simply return the pointer to our object
            return *this;
        }
        else
        {
            // Deallocate memory for an array
            delete[] data;
            // Allocate memory on the heap for an array
            data = new int[size];
            // Fill the array with data from the object that's passed in as an argument to the function recursively in a for loop
            for (std::size_t i{0}; i < size; i++)
            {
                data[i] = obj.data[i];
            }
            // Return the pointer to the object
            return *this;
        }
    }
    // Move assignment operator
    Array &operator=(const Array &&obj)
    {
        std::cout << "Move assignment operator was used" << std::endl;
        // Check if the objects are not the same
        if (this == &obj)
        {
            return *this;
        }
        else
        {
            // Deallocate memory
            delete[] data;
            // Allocate memory
            data = new int[size]{};
            // Move data from obj array to our array (transfer ownership)
            for (std::size_t i{0}; i < size; i++)
            {
                data[i] = obj.data[i];
            }
            return *this;
        }
    }
    // Fill an array with some data
    void fillArray()
    {
        for (std::size_t i{0}; i < size; i++)
        {
            data[i] = i * 2;
        }
    }
    // Set the array
    void setArray(int idx, int arrData)
    {
        data[idx] = arrData;
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
};

int main()
{
    // Instantiate a new object
    // Array arr1; // Dynamically allocated memory on the heap for a new array
    // // Fill out a dynamically allocated array
    // arr1.fillArray();
    // arr1.printArray();
    // // Now we want the copy constructor to run
    // Array arr2{arr1}; // Copy constructor should run here. So if we don't have a custom copy constructor, the compiler will give us a default copy constructor for free which will be able to make only a shallow copy of the object since it'g going to use the same memory location as the previous object
    // // Now we'll make a deep copy with its own memory address using our custom copy constructor
    // arr2.printArray();
    // // Copy assignment
    // Array arr3;
    // // Copy assignment operator should be invoked here after the object has already been constructed
    // arr3 = arr2;
    // arr3.printArray();
    Array arr1;
    arr1.fillArray();
    Array arr2{std::move(arr1)};
    arr2.printArray();
    arr1.printArray();
    arr1.setArray(0, 50);
    arr1.printArray();
    arr2.printArray();

    arr2 = std::move(arr1);
    arr2.printArray();
    arr1.printArray();

    return 0;
}