/* Character manipulation */
#include <iostream>
#include <string>

int main(void)
{
    // // Check if a character is alphanumeric
    // char letter{'/'};
    // if (std::isalpha(letter))
    // {
    //     std::cout << letter << " is alphanumeric" << std::endl;
    // }
    // else
    // {
    //     std::cout << letter << " is not alphanumeric" << std::endl;
    // }

    // Count the number of blank characters in an array of a string
    // char word[]{"Hello guys. How's it going? How are you doing today?"};
    // int blank_count{};
    // for (size_t i{0}; i < std::size(word); i++)
    // {
    //     if (std::isblank(word[i]))
    //     {
    //         std::cout << "We've encountered blank at the index of [" << i << "]" << std::endl;
    //         blank_count++;
    //     }
    // }
    // std::cout << "The number of blank characters is " << blank_count << std::endl;

    // Check if elements of a given array contain uppercase letters and transform them into lowercase letters
    char phrase[]{"What are you doing today?"};
    int lower_count{};
    // Pass by address to the array in order to modify the original array
    for (auto &x : phrase)
    {
        if (islower(x))
        {
            lower_count++;
        }
        x = toupper(x);
    }
    std::cout << "The phrase in uppercase letters: " << phrase << std::endl;
    std::cout << "The number of lowercase characters in the original phrase: " << lower_count << std::endl;
    return 0;
}