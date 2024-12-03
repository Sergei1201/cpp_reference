/* Template instantiation in C++  */
#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <typeinfo>

/* Function prototyping */
template <typename T1,typename T2>
void printNums(T1 num1, T2 num2);
/* Main function */
int main(){
	printNums<int, int>(5, 6);
	return 0;
}

/* Function definition */
template <typename T1, typename T2>
void printNums(T1 num1, T2 num2) {
	std::cout << typeid(num1).name() << std::endl;
	std::cout << typeid(num2).name() << std::endl;
}

	
