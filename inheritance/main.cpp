/* Inheritance in C++ */
#include <iostream>
#include <vector>
class Person
{
    /* Private member variables */
protected:
    std::string m_firstName{};
    std::string m_lastName{};
    int m_age{};
    /* Public member functions */
    // Constructor
public:
    explicit Person(std::string firstName, std::string lastName, int age)
        : m_firstName{firstName}, m_lastName{lastName}, m_age{age}
    {
    }
    // Base virtual function (we're using virtual inheritance in this example)
    virtual const std::string greetings() const
    {
        return "Greetings " + m_firstName + " " + m_lastName + ". You are " + std::to_string(m_age);
    }
    // Overload the << operator
    friend std::ostream &operator<<(std::ostream &os, const Person &obj);
};
// Overload the << operator
std::ostream &operator<<(std::ostream &os, const Person &obj)
{
    os << "Person's info. First name: " << obj.m_firstName << " Last name: " << obj.m_lastName << " Age: " << obj.m_age;
    return os;
}
// Child class
class Student : public Person
{
    /* Private member variables */
private:
    std::string m_subject{};
    int m_grade{};

public:
    /* Public member functions */
    // Constructor (explicit in order to prevent the compiler from converting data types in the constructor)
    explicit Student(std::string firstName, std::string lastName, int age, std::string subject, int grade)
        // Call the parent constructor in order to initialize the student
        : Person{firstName, lastName, age}, m_subject{subject}, m_grade{grade}
    {
    }
    // Override the virtual function of the base class
    const std::string greetings() const override
    {
        return "Greetings " + m_firstName + " " + m_lastName + ". You are " + std::to_string(m_age) + ". You are studying " + m_subject + ". Your grade is " + std::to_string(m_grade);
    }
    // Override the << operator in the derived class as well
    friend std::ostream &operator<<(std::ostream &os, const Student &obj);
};
// Override the << operator
std::ostream &operator<<(std::ostream &os, const Student &obj)
{
    os << "Students's info. First name: " << obj.m_firstName << " Last name: " << obj.m_lastName << " Age: " << obj.m_age << " Subject: " << obj.m_subject << " Grade: " << obj.m_grade;
    return os;
}

int main(void)
{
    // Dynamically allocate memory on the heap at runtime to instantiate Person class
    Person p1{"Sergei", "Sokolov", 40};
    Student s1{"Daniil", "Sokolov", 9, "Math", 5};
    // Declare a vector of pointers to store our object's addresses to demonstrate virtual polymorphism
    std::vector<Person *> v{};
    v.push_back(&p1);
    v.push_back(&s1);
    // Let's print the result of the greetings member function for each object (polymorphism should work here)
    for (auto obj : v)
    {
        std::cout << obj->greetings() << std::endl;
    }

    // Person *p1{new (std::nothrow) Person{"Sergei", "Sokolov", 40}};
    //  Dynamically allocate memory on the heap at runtime to instantiate Student class

    return 0;
}