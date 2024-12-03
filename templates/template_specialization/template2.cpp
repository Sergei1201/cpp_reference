/* Template practice */ 
#include <iostream>

template<typename T1, typename T2>
auto multiply(const T1& a, const T2& b){
	return a * b;
}

int main(void){
	std::cout << multiply<int, double>(5, 5) << std::endl;
	return 0;
}
