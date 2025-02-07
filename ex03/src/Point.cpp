/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:30:49 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/07 17:44:53 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Point.hpp"

/* Constructors & Destructor */
Point::Point(void)
{
	_x = 0;
	_y = 0;
	return ;
}
Point::Point(Fixed const x, Fixed const y)
{
	_x = x;
	_y = y;
	return ;
}
Point::Point(Point const & src)
{
	*this = src;
	return ;
}
Point::~Point()	{ return ; }
/*--------++---------*/

/* Operator Overload */
std::ostream	&operator<<(std::ostream & o, Point const & rhs)
{
	o << "Point: ";
	o << "X: " << rhs.getX() << " Y: " << rhs.getY();
	o << std::endl;
	return (o);
}

Point	&Point::operator=(Point const & rhs)
{
	if (this != &rhs)
	{
		_x = rhs.getX();
		_y = rhs.getY();
	}
	return (*this);
}
/*--------++---------*/

/* Getters & Setters */
Fixed	Point::getX(void) const	{ return (_x); }
Fixed	Point::getY(void) const	{ return (_y); }
void	Point::setX(Fixed const x)	{ _x = x; }
void	Point::setY(Fixed const y)	{ _y = y; }
/*--------++---------*/


