/* Multiple virtual(diamond) inheritance use-case scenario */
#include <iostream>

struct Person
{
    std::string name{};
    Person()
    {
        std::cout << "Person constructor ran..." << std::endl;
    }
    virtual ~Person()
    {
    }
};

struct Student : virtual public Person
{
    std::string course{};
    Student()
    {
        std::cout << "Student constructor ran..." << std::endl;
    }
};

struct Teacher : virtual public Person
{
    std::string specialization{};
    Teacher()
    {
        std::cout << "Teacher constructor ran..." << std::endl;
    }
};

struct PHDStudent : public Student, Teacher
{
    PHDStudent()
    {
        std::cout << "PHD constructor ran..." << std::endl;
    }
};

int main(void)
{
    PHDStudent p1;
    p1.name = "Sergei";
    std::cout << p1.name << std::endl;
    // Teacher t1;
    return 0;
}