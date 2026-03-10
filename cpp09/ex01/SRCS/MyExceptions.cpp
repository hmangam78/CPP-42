/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:43:42 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/11 11:10:33 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MyExceptions.hpp"

MyExceptions::MyExceptions() {}
MyExceptions::MyExceptions(const MyExceptions& other)
{
    (void)other;
}
MyExceptions& MyExceptions::operator=(const MyExceptions& other)
{
    (void)other;
    return (*this);
}
MyExceptions::~MyExceptions() {}

const char* MyExceptions::DivideByZero::what() const throw()
{
    return ("Divide by zero error");
}

const char* MyExceptions::NoOperands::what() const throw()
{
    return ("Not enough operands left in stack");
}

const char* MyExceptions::NoOperators::what() const throw()
{
    return ("Not enough operators to evaluate the expression");
}
