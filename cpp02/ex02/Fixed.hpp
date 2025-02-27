/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:15:22 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/26 11:40:09 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

//	Libraries
# include <iostream>
# include <cmath>

//		Class
class	Fixed
{
	private:
		int					fixed_point;
		const static int	fract = 8;
	
	public:
		Fixed(void);
		Fixed(const float value);
		Fixed(const int value);
		Fixed(const Fixed &copy);
		~Fixed(void);

		Fixed	&operator=(const Fixed &other);
		bool	operator<(const Fixed fixed);
		bool	operator>(const Fixed fixed);
		bool	operator<=(const Fixed fixed);
		bool	operator>=(const Fixed fixed);
		bool	operator==(const Fixed fixed);
		bool	operator!=(const Fixed fixed);
		Fixed	operator+(const Fixed fixed);
		Fixed	operator-(const Fixed fixed);
		Fixed	operator*(const Fixed fixed);
		Fixed	operator/(const Fixed fixed);
		Fixed	operator++();
		Fixed	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		static const Fixed	&min(const Fixed &one, const Fixed &two);
		static Fixed		&min(Fixed &one, Fixed &two);
		static const Fixed	&max(const Fixed &one, const Fixed &two);
		static Fixed		&max(Fixed &one, Fixed &two);
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		int			toInt(void) const;
		float		toFloat(void) const;
};


//	Output override
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif