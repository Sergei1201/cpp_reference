/* Introduction to templates in C++  */
#include <iostream>
#include <memory>
#include <ostream>
#include <string>

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
int squareNumber(int x);
double squareNumber(double x);

/* Main function  */
int main(void){
	// Instantiate a new person object
	Person p{"John", "Doe", 40};
	std::cout << p.greetings() << std::endl;
	
	std::cout << squareNumber(5) << std::endl;
	std::cout << squareNumber(5.5) << std::endl;

};

/* Function definition */
int squareNumber(int x){
	return x * x;
}
double squareNumber(double x) {
	return x * x;
}
