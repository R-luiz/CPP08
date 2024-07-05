#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

template <typename T>
void testEasyfind(T& container, int value)
{
    try
    {
        typename T::iterator result = easyfind(container, value);
        std::cout << "Value " << value << " found at position: " 
                  << std::distance(container.begin(), result) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    // Test with vector
    std::vector<int> vec;
    for (int i = 0; i < 5; ++i)
        vec.push_back(i * 2);

    std::cout << "Testing vector:" << std::endl;
    testEasyfind(vec, 4);
    testEasyfind(vec, 7);

    // Test with list
    std::list<int> lst;
    for (int i = 0; i < 5; ++i)
        lst.push_back(i * 3);

    std::cout << "\nTesting list:" << std::endl;
    testEasyfind(lst, 9);
    testEasyfind(lst, 10);

    // Test with deque
    std::deque<int> deq;
    for (int i = 0; i < 5; ++i)
        deq.push_back(i * 5);

    std::cout << "\nTesting deque:" << std::endl;
    testEasyfind(deq, 15);
    testEasyfind(deq, 22);

    return 0;
}