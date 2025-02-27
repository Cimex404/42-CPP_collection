/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:32:29 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/27 11:47:49 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

//	Libraries
# include <iostream>
# include "Fixed.hpp"

//	Class
class	Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &point);
		~Point(void);
		const float	get_x(void);
		const float	get_y(void);

		Point	&operator=(const Point &other);
};

//	Functions
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif