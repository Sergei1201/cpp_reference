/* Using variadic templates in C++ */
#include <iostream>

// Function prototype & declaration
template<typename T>
T sum(T num){
	return num;
}

template<typename T, typename ... Args>
T sum(T start, Args... args){
	return start + sum(args...);
}

// Main Function
int main(void){
	std::cout << sum<double>(5.5) << std::endl;
	std::cout << sum<int>(1,2,3,4,5) << std::endl;
	return 0;
}

