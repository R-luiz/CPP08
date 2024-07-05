#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
    unsigned int _N;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    template<typename Iterator>
	void addRange(Iterator begin, Iterator end) {
		while (begin != end) {
			if (_numbers.size() >= _N) {
				throw FullSpanException();
			}
			_numbers.push_back(*begin);
			++begin;
		}
	}

    class FullSpanException : public std::exception {
        const char* what() const throw();
    };

    class NoSpanException : public std::exception {
        const char* what() const throw();
    };
};

#endif