/* Template specialization in C++ */
#include <iostream>

/* Function prototype */
template <typename T>
bool isEqual(T num1, T num2) {
	return (num1 == num2);
}

int main(void) {
	std::cout << isEqual<int>(5, 6) << std::endl;
	return 0;
}

