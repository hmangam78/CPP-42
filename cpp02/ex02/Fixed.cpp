/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:36:46 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/08 17:12:13 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_nbf_bits = 8;

Fixed::Fixed(void)
{
	//std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int num)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_value = num << _nbf_bits;
}

Fixed::Fixed(const float num)
{
	double	scaled;
	int		raw;

	//std::cout << "Float constructor called" << std::endl;
	scaled = std::ldexp(static_cast<double>(num), _nbf_bits);
	if (scaled >= 0.0f)
		raw = static_cast<int>(std::floor(scaled + 0.5f));
	else
		raw = static_cast<int>(std::ceil(scaled - 0.5f));
	this->_value = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_value = other.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << _nbf_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> _nbf_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

/*Comparison operators*/
bool Fixed::operator<(const Fixed& other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>(const Fixed& other) const
{
	return(this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return(this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return(this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return(this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->getRawBits() != other.getRawBits());
}

/*Arithmetic operators*/
Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;
	result._value = this->_value + other._value;
	return result;
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;
	result._value = this->_value - other._value;
	return result;
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	result._value = (this->_value * other._value) >> _nbf_bits;
	return result;
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	if (other._value == 0)
	{
		std::cout << "Error trying to divide by 0, returned 0" << std::endl;
		return Fixed(0);
	}
	result._value = (this->_value << _nbf_bits) / other._value;
	return result;
}

/*Increments and decrements*/
Fixed& Fixed::operator++(void)
{
	_value += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	_value += 1;
	return temp;
}

Fixed& Fixed::operator--(void)
{
	_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	_value -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	else
		return (b);
}
