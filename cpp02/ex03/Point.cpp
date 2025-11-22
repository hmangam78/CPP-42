/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:39:10 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/09/29 15:10:26 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
}

Point::Point(const Fixed& x, const Fixed& y) : x(x), y(y)
{
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
}

Point::~Point()
{
}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return *this;
}

Fixed Point::get_x(void) const
{
	return (this->x);
}

Fixed Point::get_y(void) const
{
	return (this->y);
}