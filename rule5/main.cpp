/* Rule of five in C++ */
/* If any of the following are defined in a class, then you should probably consider implementing all of them
1. Destructor
2. Copy constructor
3. Copy assignment operator
4. Move constructor
5. Move assignment operator
*/
#include <iostream>

class Array
{
    /* Private member variables */
private:
    int *data{nullptr};
    const std::size_t size{10};

public:
    /* Public member functions */
    // Regular constructor
    Array()
    {
        std::cout << "Constructor ran.." << std::endl;
        // Dynamically allocate memory on the heap for an array of integers when the class is being instantiated
        data = new int[size]{};
    }
    // Regular destructor
    ~Array()
    {
        std::cout << "Destructor ran..." << std::endl;
        // Deallocate memory when an object has been destroyed to return memory back to the OS
        delete[] data;
    }
    // Custom copy constructor to make a deep copy with its own memory location of an object when the class is being instantiated with an already existing object
    Array(const Array &obj)
    {
        std::cout << "Copy constructor ran.." << std::endl;
        // When a copy is being made allocate memory on the heap to make a deep copy of an object
        data = new int[size]{};
        // Copy data from the object that's passed in as an argument (by const reference)
        for (std::size_t i{0}; i < size; ++i)
        {
            data[i] = obj.data[i];
        }
    }
    // Move constructor (it runs when we're transferring the ownership to another object when the class is being instantiated)
    Array(const Array &&obj)
    {
        std::cout << "Move constructor ran..." << std::endl;
        // Allocate memory on the heap at runtime for an array of integers when an object is being created by passing the ownership from an already existing object
        data = new int[size]{};
        // Fill the array with data of the object that's passed in as an argument
        for (std::size_t i{0}; i < size; ++i)
        {
            data[i] = obj.data[i];
        }
    }
    // Custom copy assignment operator (invoked when copying an object to an already created object)
    Array &operator=(const Array &obj)
    {
        std::cout << "Copy assignment operator is invoked..." << std::endl;
        // Make sure that the object you copy is not our object
        if (this == &obj)
        {
            // If it is, return a pointer to the object
            return *this;
        }
        else
        {
            // Otherwise, deallocate and then allocate memory on the heap to make a copy of an object
            delete[] data;
            data = new int[size]{};
            // Fill the array with data from the object that's passed in as an argument
            for (std::size_t i{0}; i < size; ++i)
            {
                data[i] = obj.data[i];
            }
        }
        return *this;
    }
    // Move assignment operator (transferring the ownership to another object after the class has been instantiated already)
    Array &operator=(const Array &&obj)
    {
        std::cout << "Move assignment operator is working..." << std::endl;
        // Make sure that we're not referencing the same object
        if (this == &obj)
        {
            // Return a pointer to the object itself
            return *this;
        }
        else // otherwise deallocate memory, allocate memory and fill an object from the passed in object
        {
            delete[] data;
            data = new int[size]{};
            for (std::size_t i{0}; i < size; ++i)
            {
                data[i] = obj.data[i];
            }
        }
        return *this;
    }
    // Fill array
    void fillArray()
    {
        for (std::size_t i{0}; i < size; ++i)
        {
            data[i] = i * 2;
        }
    }
    // Set array
    void setArray(int idx, int arrData)
    {
        data[idx] = arrData;
    }
    // Print array
    void printArray()
    {
        for (std::size_t i{0}; i < size; ++i)
        {
            std::cout << data[i] << "\t";
        }
        std::cout << std::endl;
    }
};

int main(void)
{
    // Let's instantiate the class (create an object from the class)
    Array arr1{}; // Regular constructor should run here
    // Fill the array
    arr1.fillArray();
    // Print the array
    arr1.printArray();
    // Let's create another object with and copy the existing object to it
    Array arr2{arr1}; // Now the copy constructor should run
    // Print a new array
    arr2.printArray();
    // Now let's make a copy our object to another newly created object
    Array arr3{}; // Regular constructor should run once again
    arr3 = arr2;  // Copy assignment operator should be invoked here
    arr3.printArray();
    Array arr4{std::move(arr3)}; // Move constructor should run here
    arr4.printArray();
    arr3.printArray();
    Array arr5;             // Regular constructor runs...
    arr5 = std::move(arr4); // Move assignment operator should be invoked here
    arr5.printArray();
    arr4.printArray();

    return 0;
}