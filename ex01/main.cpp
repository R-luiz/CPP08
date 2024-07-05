#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
    // Test case from the subject
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    // Test with 10,000 numbers
    {
        Span bigSpan(10000);
        std::vector<int> numbers;

        srand(time(NULL));
        for (int i = 0; i < 10000; ++i) {
            numbers.push_back(rand());
        }

        bigSpan.addRange(numbers.begin(), numbers.end());

        std::cout << "\nBig Span:" << std::endl;
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
    }

    // Test exceptions
    {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);

        try {
            sp.addNumber(3);
        } catch (const std::exception& e) {
            std::cout << "\nException caught: " << e.what() << std::endl;
        }

        Span emptySpan(5);
        try {
            emptySpan.shortestSpan();
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }

    return 0;
}