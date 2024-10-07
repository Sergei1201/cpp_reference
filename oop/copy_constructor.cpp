/* Copy constructor, copy assignment & destructors in C++ */
#include <iostream>

class Array
{
    // Private data members
private:
    // We are going to create an array dynamically, therefore create a pointer to data
    int *data{};
    size_t size{10};
    // Constructor, public member functions & destructor
public:
    // Here goes the regular constructor which is invoked when an object is being created. When creating an object, we dynamically allocate memory in the heap for an array of integer using the new operator
    Array()
    {
        std::cout << "The usual constructor ran..." << std::endl;
        data = new int[size]{};
    }
    // Destructor goes here and after an object has been destroyed we should return memory back to the operating system by manually deallocating memory

    // Explicit (custom) copy constructor to make a deep copy of an object
    Array(const Array &rhs)
    {
        std::cout << "Copy constructor ran..." << std::endl;
        // Dynamically allocate your own memory in the heap when an object is being copied
        data = new int[size]{};
        // Fill the array with the values of the first array
        for (size_t i{0}; i < size; i++)
        {
            data[i] = rhs.data[i];
        }
    }

    // Copy assignment operator runs (makes a copy of an object) when an object has already been constructed
    Array &operator=(const Array &rhs)
    {
        std::cout << "Copy assignment operator ran..." << std::endl;
        // Check if the objects points to itself, return a pointer to the object
        if (&rhs == this)
        {
            return *this;
        }
        // Otherwise, return dynamically allocated memory back to the OS
        delete[] data;
        // Reallocate memory for the object
        data = new int[size]{};
        // Fill the array with some data
        for (size_t i{0}; i < size; i++)
        {
            data[i] = rhs.data[i];
        }
        return *this;
    }

    // Destructor (returning memory back to the operating system by freeing up the memory)
    ~Array()
    {
        std::cout << "The destructor ran..." << std::endl;
        delete[] data;
    }

    /* Public member functions */

    // Fill our array with some data
    void fillArray()
    {
        for (size_t i{0}; i < size; i++)
        {
            data[i] = i * 2;
        }
    }

    // Change data in our array
    void setData(int index, int arrData)
    {
        data[index] = arrData;
    }

    // Print the array to the user
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
    // Instantiate class
    Array array1; // Usual constructor is being invoked
    array1.fillArray();
    array1.printArray();
    // Now what's going to happen if we create another object by making a copy of an existing one. What kind of counstructor will run in this particular case? It's the copy constructor (the implicit one which will make a shallow copy of an existing object since they will share the same memory location)
    // Array array2{array1}; // The implicit copy constructor will make a shallow copy
    // array2.printArray();
    // What if we want to create an object by copying an existing one with its own unique memory location (in the heap)? Here comes an explicit copy constructor which will make a full (deep) copy of the object with its own memory address
    // Array array2{array1}; // The custom copy constructor ran
    // array2.printArray();
    Array array2;    // Usual constructor should run now
    array2 = array1; // When the objects has already been constructed the copy assignment operator should run
    array2.printArray();
    // After the object has been destroyed the memory is freed (let's make sure that this is exactly the case)
}