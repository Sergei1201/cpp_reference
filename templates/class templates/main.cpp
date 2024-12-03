/* Class templates in C++ */ 
#include <cstddef>
#include <iostream>
#include <new>

template<typename T>
class Array {
	/* Private data members */
	private:
		T *m_data{};
		const std::size_t size{10};
	/* Public member functions */
	public:
		// Constructor
		Array(){
			std::cout << "Constructor ran..." << std::endl;
		        //Memory allocation on the heap when an object is being instantiated fro                           m the class
			m_data = new T[size];	
		}
		// Destructor
		~Array(){
			std::cout << "Destructor ran..." << std::endl;
			// Deallocate memory after the object has been destroyed
			delete [] m_data;
		}
		// Fill Array
		void fillArray() {
			for (std::size_t i{0}; i < size; i++) {
				m_data[i] = i * 2;
			}
		}
		// Print Array 
		void printArray() {
			for (std::size_t i{0}; i < size; i++) {
				std::cout << m_data[i] << "\t";
	
			}
			std::cout << std::endl;
		}
};

int main(void) {
	// Instantiate a new object
	Array<int> a;
	a.fillArray();
	a.printArray();
	Array<double> b;
	b.fillArray();
	b.printArray();
	return 0;
}
