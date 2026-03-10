/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:28:22 by hgamiz-g          #+#    #+#             */
/*   Updated: 2026/03/10 16:37:04 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructor, copy constructor, assignment operator and destructor
Span::Span(unsigned int size) : _capacity(size) {}

Span::Span(const Span& other) :_array(other._array), _capacity(other._capacity) {}

Span&   Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _capacity = other._capacity;
        _array = other._array;
    }
    return (*this);
}

Span::~Span(void) {}

// Add a number to the Span object
void    Span::addNumber(int num)
{
    if (_array.size() >= _capacity)
        throw (CapacityExceeded());
    else
        _array.push_back(num);
}

// Add multiple numbers to the list
void    Span::multiADD(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_array.size() + std::distance(begin, end) > _capacity)
        throw CapacityExceeded();
    _array.insert(_array.end(), begin, end);
}

// Number getter from and index
int     Span::getNumber(unsigned int index) const
{
    if (index < _array.size())
        return (_array[index]);
    else
        throw (OutOfRange());
}

// Size getter
int     Span::getSize(void) const
{
    return (_array.size());
}

// Returns the sortest span in the list of numbers
int     Span::shortestSpan(void)
{
    if (_array.size() < 2)
        throw NotEnoughElements();
    std::sort(_array.begin(), _array.end());
    int span = getNumber(1) - getNumber(0);
    for (int i = 1; i < getSize(); i++)
    {
        if (getNumber(i) - getNumber(i - 1) < span)
            span = getNumber(i) - getNumber(i - 1);
    }
    return (span);
}

// Returns the largest span in the list of numbers
int     Span::longestSpan(void)
{
    if (_array.size() < 2)
        throw NotEnoughElements();
    std::sort(_array.begin(), _array.end());
    int span = getNumber(getSize() - 1) - getNumber(0);
    return (span);
}

// Exceptions
// Capacity exceeded, when trying to add a number when th size == capacity
const char* Span::CapacityExceeded::what() const throw()
{
    return ("Span array full, can't add elements");
}

// Out of range when trying to access an element beyond the size of the list
const char* Span::OutOfRange::what() const throw()
{
    return ("Tried to access an index out of range");
}

// If trying to get span when there is 1 or 0 elements in the list
const char* Span::NotEnoughElements::what() const throw()
{
    return ("Not enough elements to get the span");
}

// Operator << overload
std::ostream& operator<<(std::ostream& os, const Span& obj)
{
    os << "[";
    int n = obj.getSize();
    for (int i = 0; i < n; i++)
    {
        os << obj.getNumber(i);
        if (i + 1 < n)
            os << ", ";
    }
    os << "]";
    return os;
}
