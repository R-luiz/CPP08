#include "Span.hpp"
#include <limits>

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _N = other._N;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _N) {
        throw FullSpanException();
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() <= 1) {
        throw NoSpanException();
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i-1];
        if (span < shortest) {
            shortest = span;
        }
    }
    return shortest;
}

int Span::longestSpan() const {
    if (_numbers.size() <= 1) {
        throw NoSpanException();
    }

    std::vector<int>::const_iterator min = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator max = std::max_element(_numbers.begin(), _numbers.end());

    return *max - *min;
}

const char* Span::FullSpanException::what() const throw() {
    return "Span is full, cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw() {
    return "Not enough numbers to calculate span";
}