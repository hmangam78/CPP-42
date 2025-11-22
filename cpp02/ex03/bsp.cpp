/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:02:45 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/09/29 15:37:25 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	ap;
	Fixed	bp;
	Fixed	cp;

	ap = ((b.get_x() - a.get_x()) * (point.get_y() - a.get_y()))
		- ((b.get_y() - a.get_y()) * (point.get_x() - a.get_x()));
	bp = ((c.get_x() - b.get_x()) * (point.get_y() - b.get_y()))
		- ((c.get_y() - b.get_y()) * (point.get_x() - b.get_x()));
	cp = ((a.get_x() - c.get_x()) * (point.get_y() - c.get_y()))
		- ((a.get_y() - c.get_y()) * (point.get_x() - c.get_x()));

	bool negatives = (ap < 0) || (bp < 0) || (cp < 0);
	bool positives = (ap > 0) || (bp > 0) || (cp > 0);
	bool zeroes = (ap == 0) || (bp == 0) || (cp == 0);

	if (zeroes)
		return (false);
	return !(negatives && positives);
}