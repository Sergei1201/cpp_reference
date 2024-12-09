/* Unique pointers in C++ */ 
#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Person {
	/* Private member variables */ 
	private:
		std::string m_firstName{};
		std::string m_lastName{};
		int m_age{};
	public:
	/* Public member functions */ 
		// Constructor
		Person(std::string firstName, std::string lastName, int age)
			: m_firstName{firstName}, m_lastName{lastName}, m_age{age} {

			}
		// Public member functions
		const std::string greetings() const {
			return "Greetings " + m_firstName + " " + m_lastName + " . You are " + std::to_string(m_age);
		}

};

int main(void) {
	// Dynamic memory allocation on the heap at runtime for an object using unique_ptr
	std::vector<std::unique_ptr<Person>>vector{};
	vector.push_back(std::make_unique<Person>("Sergei", "Sokolov", 40));
	vector.push_back(std::make_unique<Person>("Jane", "Doe", 25));
	vector.push_back(std::make_unique<Person>("John", "Doe", 35));
	for (auto &person : vector) {
		std::cout << person->greetings() << std::endl;
	}
	return 0;
}

