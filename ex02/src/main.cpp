/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:57:16 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/07 16:50:35 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Fixed.hpp"

int main(void)
{
	/* Example Test from Subject */
	std::cout << "Example Test from Subject" << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "---------******---------" << std::endl;
	/*----------------*/

	/* My Tests */
	std::cout << "My Tests" << std::endl;
	Fixed c(41);
	Fixed d(21.2f);
	Fixed e(0);

	std::cout << "c: " << c << std::endl;
	c++;
	std::cout << "c++: " << c << std::endl;
	e = c + d;
	std::cout << "e = c + d: " << e << std::endl;
	e = c - d;
	std::cout << "e = c - d: " << e << std::endl;
	e = c * d;
	std::cout << "e = c * d: " << e << std::endl;
	e = c / d;
	std::cout << "e = c / d: " << e << std::endl;
	std::cout << "min: d || c: " << Fixed::min(d, c) << std::endl;
	std::cout << "max: d || c: " << Fixed::max(d, c) << std::endl;
	std::cout << "---------******---------" << std::endl;
	/*----------------*/
	return (0);
}
