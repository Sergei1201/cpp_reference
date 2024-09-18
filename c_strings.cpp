/* C-string manipulation in C++ */
#include <iostream>
#include <cstring>

int main(void)
{

    // const char *string1{"This is the string 1"};
    // const char *string2{"This is the string 1"};
    // std::cout << "String comparison " << std::strcmp(string1, string2) << std::endl;
    // // Normal C-string
    // char message[]{"This is an example of a C-style array in the C++ programming language"};
    // // Pointer string
    // const char *message2[]{"This is another example of a C-style pointer array"};
    // // Get the length of both arrays
    // std::cout << "The length of the first array: " << std::size(message) << std::endl;
    // std::cout << "The length of pointers' array: " << std::size(message2) << std::endl;
    // std::cout << "The size of the pointer: " << sizeof(message2) << std::endl;

    // String comparison

    // Find a character in a given string
    // const char *str{"Let's find a character b in this string"};
    // const char *result = str;
    // int iterations{};
    // char target_symbol{'b'};

    // while ((result = std::strchr(str, target_symbol)) != nullptr)
    // {
    //     std::cout << "Found " << target_symbol << " starting at " << result << std::endl;
    //     result++;
    //     iterations++;
    // }

    // Copy and concatenate strings
    // String concatenation
    // char string1[50]{"Hello from CPP"};
    // char string2[50]{"Bye from CPP"};
    // std::strcat(string1, string2);
    // std::cout << string1 << std::endl;

    // // String copying
    // char string3[50]{"Hello how's it going gjys?"};
    // char string4[50]{"Is everyting alright?"};
    // std::strcpy(string3, string4);
    // std::cout << string3 << std::endl;
    return 0;
}