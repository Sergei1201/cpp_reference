/* Member initializer list */
#include <iostream>
#include <initializer_list>

class List
{
private:
    std::initializer_list<int> m_list{};

public:
    List(std::initializer_list<int> list)
        : m_list(list)
    {
    }
    void printList()
    {
        for (auto &i : m_list)
        {
            std::cout << i << std::endl;
        }
        std::cout << std::endl;
    }
};

int main(void)
{
    List l1{1, 2, 3, 4, 5, 6};
    l1.printList();
    return 0;
}