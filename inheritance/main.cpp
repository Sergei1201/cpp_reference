/* Inheritance example in C++ */
#include <iostream>
#include <cmath>

class Person
{
protected:
    std::string m_firstName{};
    std::string m_lastName{};
    int m_age{};

public:
    explicit Person(std::string firstName, std::string lastName, int age)
        : m_firstName{firstName}, m_lastName{lastName}, m_age{age}
    {
    }
    virtual const std::string greetings() const
    {
        return "Greetings " + m_firstName + " " + m_lastName + ". You are " + std::to_string(m_age);
    }
    // Declare a friend function inside the class to overload << operator (access private and protected member variables of the class)
    friend std::ostream &operator<<(std::ostream &os, const Person &obj);
};
// Overload << operator (free function)
std::ostream &operator<<(std::ostream &os, const Person &obj)
{
    os << "Person's info. First name: " << obj.m_firstName << ". Last name: " << obj.m_lastName << ". Age: " << obj.m_age;
    return os;
}
// Public Inheritance
class Student : public Person
{
private:
    double m_grade{};
    std::string m_course{};

public:
    explicit Student(std::string firstName, std::string lastName, int age, float grade, std::string course)
        // Calling the parent constructor
        : Person{firstName, lastName, age}, m_grade{grade}, m_course{course}
    {
    }
    // Override the parent member function (virtual polymorphism)
    const std::string greetings() const override
    {
        return "Greetings " + m_firstName + " " + m_lastName + ". You are " + std::to_string(m_age) + ". Your grade is " + std::to_string(m_grade) + ". Your course is " + m_course;
    }
    // Friend function for overloading << operator
    friend std::ostream &operator<<(std::ostream &os, const Student &obj);
};
// Overload << operator (free function)
std::ostream &operator<<(std::ostream &os, const Student &obj)
{
    os << "Students's info. First name: " << obj.m_firstName << ". Last name: " << obj.m_lastName << ". Age: " << obj.m_age << ". Grade: " << obj.m_grade << ". Course: " << obj.m_course;
    return os;
}

int main(void)
{
    // Instantiate the Person class (base class)
    Person p1{"Sergei", "Sokolov", 40};
    std::cout << p1 << std::endl;
    std::cout << p1.greetings() << std::endl;
    // Instantiate the Student class (derived class)
    Student s1{"Daniil", "Sokolov", 10, 5, "Math"};
    std::cout << s1 << std::endl;
    // Check out if we were able to override the parent member function
    std::cout << s1.greetings() << std::endl;
    return 0;
}