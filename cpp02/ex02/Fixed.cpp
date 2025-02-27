/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:21:32 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/27 08:43:18 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//	Default constructor
Fixed::Fixed(void)
{
	this->fixed_point = 0;
}

//	Copy Contructor
Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

//	Integer Constructor
Fixed::Fixed(const int value)
{
	this->fixed_point = value << this->fract;
}

//	Integer Constructor
Fixed::Fixed(const float value)
{
	this->fixed_point = roundf(value * (1 << this->fract));
}

//	Deconstructor
Fixed::~Fixed(void)	{}


//	Copy operator override
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this == &other)
		return (*this);
	this->fixed_point = other.getRawBits();
	return (*this);
}


//	Bit functions
int		Fixed::getRawBits(void) const
{
	return (this->fixed_point);
}

void	Fixed::setRawBits(const int raw)
{
	this->fixed_point = raw;
}



//	Conversion functions
int		Fixed::toInt(void) const
{
	return (this->fixed_point >> this->fract);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixed_point / (float)(1 << this->fract));
}


//	Override of comparison operators
bool	Fixed::operator<(Fixed fixed)
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>(Fixed fixed)
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed)
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed)
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed)
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed)
{
	return (this->toFloat() != fixed.toFloat());
}


//	Override of arithmatic operators
Fixed	Fixed::operator+(Fixed fixed)
{
	return (this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(Fixed fixed)
{
	return (this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(Fixed fixed)
{
	return (this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(Fixed fixed)
{
	return (this->toFloat() / fixed.toFloat());
}


//	Override of inc/-decrement operators
Fixed	Fixed::operator++()			//Pre
{
	this->fixed_point ++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->fixed_point --;
	return (*this);
}

Fixed	Fixed::operator++(int)		//Post
{
	Fixed	result;

	result = *this;
	++this->fixed_point;
	return (result);
}

Fixed	Fixed::operator--(int)
{
	Fixed	result;
	
	result = *this;
	--this->fixed_point;
	return (result);
}


//	Max and min
Fixed	&Fixed::min(Fixed &one, Fixed &two)
{
	return (one.toFloat() < two.toFloat()) ? one : two;
}

const Fixed	&Fixed::min(const Fixed &one, const Fixed &two)
{
	return (one.toFloat() < two.toFloat()) ? one : two;
}

Fixed	&Fixed::max(Fixed &one, Fixed &two)
{
	return (one.toFloat() > two.toFloat()) ? one : two;
}

const Fixed	&Fixed::max(const Fixed &one, const Fixed &two)
{
	return (one.toFloat() > two.toFloat()) ? one : two;
}


//	Override of the insertion operator
std::ostream	&operator<<(std::ostream &out, const Fixed &number)
{
	out << number.toFloat();
	return (out);
}