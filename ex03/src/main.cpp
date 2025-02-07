/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:57:16 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/07 19:10:32 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Point.hpp"

int main(void)
{
	/* Point is in triangle test */
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(5), Fixed(0));
	Point c(Fixed(0), Fixed(5));
	Point point(Fixed(2), Fixed(2));

	std::cout << "Point might be inside of triangle->" << std::endl;
	if (bsp(a, b, c, point))
		std::cout << "Point is in triangle" << std::endl;
	else
		std::cout << "Point is not in triangle" << std::endl;
	std::cout << "---------******---------" << std::endl;

	/* Point is not in triangle test */
	Point a2(Fixed(0), Fixed(0));
	Point b2(Fixed(5), Fixed(0));
	Point c2(Fixed(0), Fixed(5));
	Point point2(Fixed(2), Fixed(3));

	std::cout << "Point might be outside of triangle->" << std::endl;
	if (bsp(a2, b2, c2, point2))
		std::cout << "Point is in triangle" << std::endl;
	else
		std::cout << "Point is not in triangle" << std::endl;
	std::cout << "---------******---------" << std::endl;

	/* Point is on edge (So return might be false) */
	Point a3(Fixed(0), Fixed(0));
	Point b3(Fixed(5), Fixed(0));
	Point c3(Fixed(0), Fixed(5));
	Point point3(Fixed(0), Fixed(0));

	std::cout << "Point might be on edge of triangle->" << std::endl;
	if (bsp(a3, b3, c3, point3))
		std::cout << "Point is in triangle" << std::endl;
	else
		std::cout << "Point is not in triangle" << std::endl;
	std::cout << "---------******---------" << std::endl;

	return (0);
}
