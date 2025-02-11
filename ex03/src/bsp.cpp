/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:38:31 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/11 17:02:29 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "inc/Point.hpp"

Fixed	dist(Fixed ax, Fixed ay, Fixed bx, Fixed by)
{
	Fixed	dx;
	Fixed	dy;
	float	result;

	dx = bx - ax;
	dy = by - ay;
	dx = dx * dx;
	dy = dy * dy;
	result = sqrt(dx.toFloat() + dy.toFloat());
	Fixed	f_result(result);
	return (f_result);
}

/* Check if the point is inside the triangle */
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (point.getX() == a.getX() && point.getY() == a.getY())
		return (false);
	if (point.getX() == b.getX() && point.getY() == b.getY())
		return (false);
	if (point.getX() == c.getX() && point.getY() == c.getY())
		return (false);

	Fixed	ab = dist(a.getX(), a.getY(), b.getX(), b.getY());
	Fixed	bc = dist(b.getX(), b.getY(), c.getX(), c.getY());
	Fixed	ca = dist(c.getX(), c.getY(), a.getX(), a.getY());
	Fixed	ap = dist(a.getX(), a.getY(), point.getX(), point.getY());
	Fixed	bp = dist(b.getX(), b.getY(), point.getX(), point.getY());
	Fixed	cp = dist(c.getX(), c.getY(), point.getX(), point.getY());

	Fixed	abc = ab + bc + ca;
	Fixed	pab = ab + ap + bp;
	Fixed	pbc = ab + bc + bp;
	Fixed	pca = ca + cp + ap;

	return ((pab + pbc + pca) == abc);
}
