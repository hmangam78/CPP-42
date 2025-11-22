/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:36:51 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/09/28 18:12:02 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int					_value;
	static const int	_nbf_bits;
public:
	Fixed(void);
	~Fixed();
	Fixed(const Fixed& other);
	Fixed(const int num);
	Fixed(const float num);
	Fixed& operator=(const Fixed& other);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
		/*conversions*/
	float	toFloat(void) const;
	int		toInt(void) const;
		/*Comparison operators*/
	bool operator<(const Fixed& other) const;
	bool operator>(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
		/*Arithmetic operations*/
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
		/*Increments and decrements*/
	Fixed& operator++(void); //Pre-increment
	Fixed  operator++(int); //Post-increment
	Fixed& operator--(void); //Pre-decrement
	Fixed  operator--(int); //Post-decrement
		/*Min & Max*/
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif