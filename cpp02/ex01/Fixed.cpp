/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:21:32 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/27 08:42:47 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//	Default constructor
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

//	Copy Contructor
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

//	Integer Constructor
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = value << this->fract;
}

//	Float Constructor
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf(value * (1 << this->fract));
}

//	Deconstructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}


//	Copy operator override
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
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


//	Override of the insertion operator
std::ostream	&operator<<(std::ostream &out, const Fixed &number)
{
	out << number.toFloat();
	return (out);
}