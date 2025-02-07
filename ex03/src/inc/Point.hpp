/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:29:22 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/07 19:00:50 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(Fixed const x, Fixed const y);
		Point(Point const & src);
		~Point();

		Point	&operator=(Point const & rhs);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
		void	setX(Fixed const x);
		void	setY(Fixed const y);

	private:
		Fixed	_x;
		Fixed	_y;
};

std::ostream	&operator<<(std::ostream & o, Point const & rhs);

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
