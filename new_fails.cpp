#include <iostream>
#include <string>

int main(void)
{
    // Let's try to exhaust the memory capabilities for the sake of the example to see how new fails
    for (size_t i{0}; i < 1000000000000; i++)
    {
        try
        {
            // Dynamically allocate an array of integers on the heap
            int *arr{new int[10000000000]};
            // After compiling and running this program we'll see that the dynamic memory has been exhausted and the program crashes. In order to avoid this behaviour we need to throw an exception
        }
        catch (std::exception &e)
        {
            std::cout << "We've encountered an exception " << e.what() << "during program's execution" << std::endl;
        }
    }
}