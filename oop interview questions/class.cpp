/* Describe what a class is. User a concrete example */
// A class serves as a blueprint for an object which has member variables and member functions (constructor, destructor, copy constructor, copy assignment operator, move constructor, move assignment operator. Example is below)
#include <iostream>
#include <memory>

class Array
{
private:
    /* Private member variables */
    const std::size_t size{10};
    int *data{};

public:
    /* Public member functions */
    // Regular constructor
    Array()
    {
        std::cout << "Constructor ran..." << std::endl;
        // Dynamically allocate memory on the heap at runtime for an object (an instance of the class, i.e an array)
        data = new int[size]{};
    }
    // Destructor
    ~Array()
    {
        std::cout << "Destructor ran..." << std::endl;
        // Deallocate memory (return it back to the operating system when the object has been destroyed (RAII technique))
        delete[] data;
    }
    // Copy constructor (it runs when we instantiate an object from a class by passing an existing object to it as an argument. Use the copy constructor when there's a need to make a deep copy with its own memory location because although the compiler gives us for free a default copy constuctor, it makes only a shallow copy with a shared memory
    Array(const Array &obj)
    {
        std::cout << "Copy constructor ran..." << std::endl;
        // In this particular example when copy constructing an object we allocate memory on the heap at runtime for an array of ints and copy the existing array to this memory location by passing it by reference as an argument to the constructor
        data = new int[size]{};
        // Copy data to this memory block
        for (std::size_t i{0}; i < size; ++i)
        {
            data[i] = obj.data[i];
        }
    }
    // Copy assignment operator is used when a copy of an already existing object is being made
    Array &operator=(const Array &obj)
    {
        std::cout << "Copy assignment operator..." << std::endl;
        // We should make sure that we don't copy an object to itself
        if (this == &obj)
        {
            // If this is the case, just return a pointer to this object
            return *this;
        }
        else
        {
            // Otherwise deallocate memory on the heap in use to make a copy
            delete[] data;
            // Allocate memory on the heap to copy data to that memory location
            data = new int[size]{};
            // Copy data to the memory block which has been allocated
            for (std::size_t i{0}; i < size; ++i)
            {
                data[i] = obj.data[i];
            }
            // Return a pointer to the object
            return *this;
        }
    }
    // Move constructor (give the ownership to a new object without having to make a copy)
    Array(const Array &&obj)
    {
        std::cout << "Move constructor ran..." << std::endl;
        // Allocate memory on the heap for an array at runtime
        data = new int[size]{};
        // Construct a new object by passing the ownership to the newly created object
        for (std::size_t i{0}; i < size; ++i)
        {
            data[i] = obj.data[i];
        }
    }
    // Move assignment operator is used when we pass the ownership to the existing object without having to make a copy
    Array &operator=(const Array &&obj)
    {
        std::cout << "Move assignment operator..." << std::endl;
        // Make sure you don't pass the object to the existing one
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
            // Fill array
            for (std::size_t i{0}; i < size; ++i)
            {
                data[i] = obj.data[i];
            }
            return *this;
        }
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
    Array arr1;        // Regular constructor runs
    arr1.fillArray();  // Fill array
    arr1.printArray(); // Print array
    Array arr2{arr1};  // Copy constuctor runs
    arr2.printArray();
    Array arr3;  // Regular constructor runs
    arr3 = arr2; // Copy assignment operator used
    arr3.printArray();
    Array arr4{std::move(arr3)}; // Move constructor runs here
    arr3.printArray();
    arr4.printArray();
    Array arr5;
    arr5 = std::move(arr4); // Move assignment operator used here
    arr5.printArray();
    return 0;
}