/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:58:44 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/06 20:00:10 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Fixed.hpp"

/* Constructors & Destructor */
Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}
Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << this->_fractionalBits;
	return ;
}
Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
	return ;
}
Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}
/* ----- */

/* Operator Overload */
std::ostream	&operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

Fixed	&Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

// Arithmetic
bool	Fixed::operator>(Fixed const & rhs) const	{ return (this->_fixedPointValue > rhs.getRawBits()); }
bool	Fixed::operator<(Fixed const & rhs) const	{ return (this->_fixedPointValue < rhs.getRawBits()); }
bool	Fixed::operator>=(Fixed const & rhs) const	{ return (this->_fixedPointValue >= rhs.getRawBits()); }
bool	Fixed::operator<=(Fixed const & rhs) const	{ return (this->_fixedPointValue <= rhs.getRawBits()); }
bool	Fixed::operator==(Fixed const & rhs) const	{ return (this->_fixedPointValue == rhs.getRawBits()); }
bool	Fixed::operator!=(Fixed const & rhs) const	{ return (this->_fixedPointValue != rhs.getRawBits()); }

// Operations
Fixed	Fixed::operator+(Fixed const & rhs) const	{ return (Fixed(this->toFloat() + rhs.toFloat())); }
Fixed	Fixed::operator-(Fixed const & rhs) const	{ return (Fixed(this->toFloat() - rhs.toFloat())); }
Fixed	Fixed::operator*(Fixed const & rhs) const	{ return (Fixed(this->toFloat() * rhs.toFloat())); }
Fixed	Fixed::operator/(Fixed const & rhs) const	{ return (Fixed(this->toFloat() / rhs.toFloat())); }

// Increment & Decrement
Fixed	&Fixed::operator++(void)	{ this->_fixedPointValue++; return (*this); }
Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}
Fixed	&Fixed::operator--(void)	{ this->_fixedPointValue--; return (*this); }
Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}
/*------*/

/* Min & Max */
//											Condition ? True : False
Fixed	&Fixed::min(Fixed & a, Fixed & b)	{ return (a < b ? a : b); }
Fixed	&Fixed::max(Fixed & a, Fixed & b)	{ return (a > b ? a : b); }
//														const_cast<type>(variable) -> cast away the constness of the variable
Fixed	&Fixed::min(const Fixed & a, const Fixed & b)	{ return (a < b ? const_cast<Fixed&>(a) : const_cast<Fixed&>(b)); }
Fixed	&Fixed::max(const Fixed & a, const Fixed & b)	{ return (a > b ? const_cast<Fixed&>(a) : const_cast<Fixed&>(b)); }
/*-----*/

/* Get & Set */
int		Fixed::getRawBits(void) const		{	return (this->_fixedPointValue);	}
void	Fixed::setRawBits(int const raw)	{	this->_fixedPointValue = raw;		}
/*----*/

/* Conversion */
float	Fixed::toFloat(void) const	{ return ((float)this->_fixedPointValue / (1 << this->_fractionalBits)); }
int		Fixed::toInt(void) const	{ return (this->_fixedPointValue >> this->_fractionalBits); }
/*-----*/
