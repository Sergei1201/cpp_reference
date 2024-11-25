/* Virtual inheritance in C++
Virtual inheritance is a C++ programming technique that ensures only one copy of a Base class will be made in a grand-child class in order to avoid ambiguity when using multiple inheritance (diamond inheritance)
*/
#include <iostream>

struct Person
{
public:
    std::string m_name{};
    // Constructor
    Person()
    {
        std::cout << "Person constructor ran..." << std::endl;
    }
    // Destructor
    virtual ~Person()
    {
        std::cout << "Person destructor ran..." << std::endl;
    }
};
// Public inheritance
struct Teacher : virtual public Person
{
protected:
    std::string m_course{};

public:
    // Constructor
    Teacher()
    {
        std::cout << "Teacher constructor ran..." << std::endl;
    }
    // Destructor
    ~Teacher()
    {
        std::cout << "Teacher destructor ran..." << std::endl;
    }
};
struct Student : virtual public Person
{
protected:
    std::string specialization{};

public:
    // constructor
    Student()
    {
        std::cout << "Student constructor ran..." << std::endl;
    }
};
// Grand child class
struct PHDStudent : public Teacher, public Student
{
public:
    // Constructor
    PHDStudent()
    {
        std::cout << "PHDStudent constructor ran..." << std::endl;
    }
    // Destructor
    ~PHDStudent()
    {
        std::cout << "PHDStudent destructor ran..." << std::endl;
    }
};

int main(void)
{
    PHDStudent phd;
    phd.m_name = "Sergei";
    std::cout << phd.m_name << std::endl;
    return 0;
}