/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:22:24 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/21 13:32:52 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

class Span
{
    private:
        std::vector<int>    _array;
        unsigned int        _capacity;
    public:
        Span(unsigned int size);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span(void);
        
        void    addNumber(int num);
        void    multiADD(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int     getNumber(unsigned int index) const;
        int     getSize(void) const;
        
        int     shortestSpan(void);
        int     longestSpan(void);
        
        class CapacityExceeded : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class OutOfRange : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class NotEnoughElements : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Span& obj);
