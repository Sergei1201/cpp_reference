#include <iostream>
#include <string>

int main(void)
{
    std::cout << "Integer: " << sizeof(int) << std::endl;
    std::cout << "Long: " << sizeof(long) << std::endl;
    std::cout << "Short: " << sizeof(short) << std::endl;
    std::cout << "Bool: " << sizeof(bool) << std::endl;
    std::cout << "Char: " << sizeof(char) << std::endl;
    std::cout << "Double: " << sizeof(double) << std::endl;
    std::cout << "Float: " << sizeof(float) << std::endl;
    std::cout << "String: " << sizeof(std::string) << std::endl;
    std::cout << "Unsigned: " << sizeof(unsigned) << std::endl;
    std::cout << "Long Long: " << sizeof(long long) << std::endl;
    return 0;
}