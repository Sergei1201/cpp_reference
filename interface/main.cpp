/* Interface introduction in C++ */
#include <iostream>
#include <vector>
/* Let's define a base "abstract" class which will have no implementation and which we will derive from to implement all the methods of this base class in the derived */
class Person // It's our interface/abstract class whose methods must be implemented in derived classes
{
protected:
    std::string m_firstName{};
    std::string m_lastName{};

public:
    Person(std::string firstName, std::string lastName)
        : m_firstName{firstName}, m_lastName{lastName} {}
    // Virtual destructor is needed if we plan to implement virtual polymorphism in derived classes
    virtual ~Person()
    {
    }
    // Pure virtual functions which we must implement in a derived class
    virtual std::string greetings() const = 0; // Must be implemented in a derived class
    virtual std::string getName() const = 0;   // Must be implemented in a derived class
};
// Derived class
class Student : public Person
{
private:
    int m_age{};
    std::string m_subject{};

public:
    // Constructor
    Student(std::string firstName, std::string lastName, int age, std::string subject)
        : Person(firstName, lastName), m_age{age}, m_subject{subject}
    {
    }
    ~Student()
    {
        std::cout << "The student destructor ran.." << std::endl;
    }
    // Public member functions
    std::string greetings() const override
    {
        return "Greetings " + m_firstName + " " + m_lastName + ". You are " + std::to_string(m_age);
    }
    std::string getName() const override
    {
        return m_firstName + " " + m_lastName;
    }
};
class Teacher : public Person
{
private:
    std::string m_specialization{};

public:
    // Constructor
    Teacher(std::string firstName, std::string lastName, std::string specialization)
        : Person(firstName, lastName), m_specialization{specialization}
    {
    }
    ~Teacher()
    {
        std::cout << "The teacher destructor ran.." << std::endl;
    }
    // Public member functions
    std::string greetings() const override
    {
        return "Greetings " + m_firstName + " " + m_lastName + " Your specialization is " + m_specialization;
    }
    std::string getName() const override
    {
        return m_firstName + " " + m_lastName;
    }
};

int main(void)
{
    Student s1{"Sergei", "Sokolov", 40, "Math"};
    Teacher t1{"Jane", "Doe", "Mathematics"};
    std::vector<Person *> p{};
    p.push_back(&s1);
    p.push_back(&t1);
    for (auto person : p)
    {
        std::cout << person->greetings() << std::endl;
    }
    return 0;
}