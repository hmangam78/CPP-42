/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:39:04 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/09/29 15:09:57 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"


class Point
{
private:
	const Fixed	x;
	const Fixed	y;
	
public:
	Point(void);
	Point(const Fixed& x, const Fixed& y);
	Point(const Point& other);
	~Point();
	Point& operator=(const Point& other);
	Fixed get_x(void) const;
	Fixed get_y(void) const;
};


#endif