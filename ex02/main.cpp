#include <iostream>
#include <list>
#include "MutantStack.hpp"

template <typename T>
void printContainer(T& container)
{
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();
    
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

int main()
{
    // Test MutantStack
    {
        std::cout << "Testing MutantStack:" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        
        std::cout << "Top: " << mstack.top() << std::endl;
        
        mstack.pop();
        
        std::cout << "Size: " << mstack.size() << std::endl;
        
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        std::cout << "Contents: ";
        printContainer(mstack);
        
        std::cout << "Reverse order: ";
        MutantStack<int>::reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::reverse_iterator rite = mstack.rend();
        while (rit != rite)
        {
            std::cout << *rit << " ";
            ++rit;
        }
        std::cout << std::endl;
    }
    
    // Test with std::list for comparison
    {
        std::cout << "\nTesting std::list:" << std::endl;
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        
        std::cout << "Back: " << lst.back() << std::endl;
        
        lst.pop_back();
        
        std::cout << "Size: " << lst.size() << std::endl;
        
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);
        
        std::cout << "Contents: ";
        printContainer(lst);
        
        std::cout << "Reverse order: ";
        std::list<int>::reverse_iterator rit = lst.rbegin();
        std::list<int>::reverse_iterator rite = lst.rend();
        while (rit != rite)
        {
            std::cout << *rit << " ";
            ++rit;
        }
        std::cout << std::endl;
    }
    
    return 0;
}