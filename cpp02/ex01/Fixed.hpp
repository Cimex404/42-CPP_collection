/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:15:22 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/26 11:40:00 by jgraf            ###   ########.fr       */
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
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
};


//	Output override
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif