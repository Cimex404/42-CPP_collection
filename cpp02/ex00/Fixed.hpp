/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:15:22 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/27 08:41:28 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

//	Libraries
# include <iostream>

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
		Fixed(Fixed &copy);
		~Fixed(void);

		Fixed	&operator=(const Fixed &other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif