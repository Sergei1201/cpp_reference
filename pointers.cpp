// #include <iostream>
// #include <string>

// int main(void)
// {
//     // Regular pointers
//     int x{15};
//     int m{20};
//     int *p{&x};
//     int y{};
//     int *z{nullptr};
//     int *k{&m};
//     // Double pointers
//     int **b{&k};
//     std::cout << "Double pointer points to " << b << std::endl;
//     std::cout << "Single pointer has the address of " << &k << std::endl;
//     std::cout << "The single pointer points to " << k << std::endl;
//     std::cout << "And now I want to change the address at which the single pointer is pointing to. How can I do that?" << std::endl;
//     std::cout << "I can do it with the double pointer. Right?" << std::endl;
//     *b = &x;
//     std::cout << "Now the single pointer is pointing at the address of " << k << std::endl;
//     std::cout << p << std::endl;
//     *p = 20;
//     std::cout << *p << std::endl;
//     p = &y;
//     std::cout << p << std::endl;
//     std::cout << "The z pointer should now be pointing to nothing " << z << std::endl;
//     z = &y;
//     std::cout << "The z pointer is now pointing at " << z << std::endl;
//     return 0;
// }

// Dereferencing a pointer
// #include <iostream>

// int main(void)
// {
//     int *p{nullptr};
//     int x{10};
//     int y{15};
//     p = &x;
//     std::cout << p << std::endl;
//     std::cout << *p << std::endl;
//     p = &y;
//     std::cout << p << std::endl;
//     std::cout << *p << std::endl;

//     return 0;
// }

// Pointer to a character
// #include <iostream>
// #include <string>
// int main(void)
// {
//     char *ptr{nullptr};
//     char char1{'B'};
//     ptr = &char1;
//     std::cout << "The pointer to char is: " << ptr << std::endl;
//     std::cout << "The value at the pointer to char: " << *ptr << std::endl;

//     return 0;
// }

// Character's array
// #include <iostream>
// #include <string>

// int main(void)
// {
//     char string1[]{"Hello from C++"};
//     string1[0] = 'B';
//     std::cout << string1 << std::endl;
// }

#include <iostream>
#include <string>

int main(void)
{
    const char *string1{"Hello from C++"};
    std::cout << string1 << std::endl;
    std::cout << *string1 << std::endl;
    return 0;
}