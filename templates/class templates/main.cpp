/* Templates in C++ and revisiting rules of 3, 5 when working with classes */ 
/* The rule of 5 says that if in your class you define a copy constructor, copy assignment operator, and destructor, then you should probarly consider implementing all of them plus consider implementing move constructor, move assignment operator
 */

#include <cstddef>
#include <iostream>
#include <memory>
#include <utility>

template <typename T>
class Array {
	/* Private member variables */
	private:
		std::size_t size{10}; // Size of the array
		T *m_data{nullptr}; // Dynamic memory for array of int
	public:
	       // Constructor
	       Array() {
			std::cout << "Constructor ran..." << std::endl;
			// Dynamic memory allocation on the heap when the class is being instantiated 
			m_data = new T[this->size];
	       }
	       // Copy constructor for making a deep copy of the object with its own unique memory location in the memory
	       Array(const Array &obj) {
		       std::cout << "Copy constructor ran..." << std::endl;
			// Dynamic memory allocation on the heap for a new object
			this->m_data = new T[this->size];
			for (std::size_t i{0}; i < this->size; i++) {
				this->m_data[i] = obj.m_data[i];
 			}
	       };
	       // Copy assignment operator (works when a copy of an existing object is being made)
	      Array &operator=(const Array &other) {
		      std::cout << "Copy assignment operator ran..." << std::endl;
		      // Make sure that the object copied is not pointing to itself
		      if (&other == this) {
			      return *this;
		      } else {
				// Deallocate memory 
				delete [] this->m_data;
				// Allocate memory on the heap
				this->m_data = new T[this->size];
				// Fill array with data (copy assignment)
				for (std::size_t i{0}; i < this->size; i++) {
					this->m_data[i] = other.m_data[i];
				}
				return *this;

		      } 

	      }
	      // Move constructor for transferring ownership to another (created) object when an object is being created from the class
	      Array(const Array &&obj) {
		      	std::cout << "Move constructor ran..." << std::endl;
			// Allocate memory on the heap
			this->m_data = new T[this->size];
			// Fill array with some data 
			for (std::size_t i{0}; i < this->size; i++) {
				this->m_data[i] = obj.m_data[i];
			}
			
	      }
	      // Move assignment operator for transferring the ownership from one object to another
	      Array &operator=(const Array &&other) {
		        std::cout << "Move assignment operator ran..." << std::endl;
			// Make sure the object copied is not pointing to itself
			if (&other == this) {
				return *this;
			} else {
				// Deallocate memory
				delete [] this->m_data;
				// Allocate memory on the heap for an object
				this->m_data = new T[this->size];
				// Fill array with some data
				for (std::size_t i{0}; i < this->size; i++) {
					this->m_data[i] = other.m_data[i];
				}
				return *this;
			}
	      }
	       // Destructor
	       ~Array() {
		       std::cout << "Destructor ran..." << std::endl;
		       // Deallocate memory after the object has been destroyed
		       delete [] m_data;
	       }
	       /* Public member functions */ 

	       // Fill array with data
	       void fillArray() {
		       for (std::size_t i{0}; i < size; i++) {
			       m_data[i] = i * 2;
		       }

	       }
	       // Print array to the user
	       void printArray() {
		      for (std::size_t i{0}; i < size; i++) {
				std::cout << m_data[i] << "\t";
		      }
		      std::cout << std::endl;
	       }
};

/* Main function */ 
int main(void) {
/*
// Instantiate the class (create an object)
Array <int>arr1;
// Fill the array
arr1.fillArray();
// Print the array to the user
arr1.printArray();
// Default copy constructor that the compiler generously prives us for free but makes a shallow copy of the object
//Array <int>arr2{arr1};
// Make a deep copy with the custom copy constructor
Array <int>arr2{arr1};
arr2.printArray();
// Copy assignment operator works when we make a copy of an existing object
Array <int>arr3{arr1};
arr3 = arr2; // Copy assignment operator should be implemented over here
arr3.printArray();
*/
Array <int>arr1;
arr1.fillArray();
arr1.printArray();
Array <int>arr2{arr1}; // Copy constructor ran
Array <int> arr3 = std::move(arr1); // Move constructor ran
arr3.printArray();
arr3 = std::move(arr2); // Move assignment operator ran
arr3.printArray();


}
