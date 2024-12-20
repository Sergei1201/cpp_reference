/* Introduction to templates in C++  */
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

class Person {
	private:
		// Private data members 
		std::string m_firstName{};
		std::string m_lastName{};
		int m_age{};
	public:
		Person(std::string firstName, std::string lastName, int age)
			: m_firstName{firstName}, m_lastName{lastName}, m_age{age}{

			}
		/* Public member functions */
		const std::string greetings() const {
			return "Greetings " + m_firstName + " " + m_lastName;
		}
	

};
	

/* Function prototyping */
template <typename T> // Templates come in handy when function overloading is used
T squareNumber(T x);
// double squareNumbe:r(double x);

/* Main function  */
int main(void){
	// std::vector<int>v{};
	// Instantiate a new person object
	Person p{"John", "Doe", 40};
	std::cout << p.greetings() << std::endl;
	
	std::cout << squareNumber<int>(5) << std::endl;
	std::cout << squareNumber<double>(5.5) << std::endl;

};

/* Function definition */
template <typename T>
T squareNumber(T x){
	return x * x;
}
/* double squareNumber(double x) {
	return x * x;
}*/
