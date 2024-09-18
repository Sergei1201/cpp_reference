#include <iostream>
#include <string>

int main(void)
{
    // Dangling pointers
    // int *ptr; // The pointer hasn't been initialized (points to some unknown memory address)
    // int y{10};
    // // std::cout << "The pointer is pointing at the address: " << ptr << std::endl;
    // // std::cout << "The value at the address pointed by the pointer: " << *ptr << std::endl;

    // // Using a pointer where the memory has been released to the OS (using dynamic memory allocation at runtime in this example)
    // int *ptr2{new int(50)};
    // std::cout << "The pointer holds the memory address: " << ptr2 << std::endl;
    // std::cout << "The value at the memory the pointer is pointing at: " << *ptr2 << std::endl;
    // // Release the memory back to the OS
    // delete ptr2;
    // // If you reuse this very pointer next time before setting it to nullptr, you'll get a dangling pointer
    // std::cout << "The value at the address the pointer is pointing at right now: " << *ptr2 << std::endl;

    /* Using multiple pointers which point at the same block of memory can crash your program */
}