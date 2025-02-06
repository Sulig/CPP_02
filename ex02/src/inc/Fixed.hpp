/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:57:28 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/06 17:54:06 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>
# include <string>

class Fixed
{
	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const & src);
		~Fixed();

		Fixed			&operator=(Fixed const & rhs);
		bool			operator>(Fixed const & rhs) const;
		bool			operator<(Fixed const & rhs) const;
		bool			operator>=(Fixed const & rhs) const;
		bool			operator<=(Fixed const & rhs) const;
		bool			operator==(Fixed const & rhs) const;
		bool			operator!=(Fixed const & rhs) const;

		Fixed			operator+(Fixed const & rhs) const;
		Fixed			operator-(Fixed const & rhs) const;
		Fixed			operator*(Fixed const & rhs) const;
		Fixed			operator/(Fixed const & rhs) const;

		Fixed			&operator++(void);	// Prefix
		Fixed			operator++(int);	// Postfix
		Fixed			&operator--(void);	// Prefix
		Fixed			operator--(int);	// Postfix

		static Fixed	&min(Fixed & a, Fixed & b);
		static Fixed	&min(const Fixed & a, const Fixed & b);
		static Fixed	&max(Fixed & a, Fixed & b);
		static Fixed	&max(const Fixed & a, const Fixed & b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream & o, Fixed const & rhs);

#endif
