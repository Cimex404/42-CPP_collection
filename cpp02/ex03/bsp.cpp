/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:36:08 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/27 12:14:11 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	get_area(Point a, Point b, Point c)
{
	Fixed	result((a.get_x() * (b.get_y() - c.get_y())
					+ b.get_x() * (c.get_y() - a.get_y())
					+ c.get_x() * (a.get_y() - b.get_y())) / 2);
	if (result < 0)
		result = result * (-1);
	return (result);
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed	total;
	Fixed	pab;
	Fixed	pbc;
	Fixed	pac;

	total = get_area(a, b, c);
	pab = get_area(point, a, b);
	pbc = get_area(point, b, c);
	pac = get_area(point, c, a);

	if (total == 0 || pab == 0 || pbc == 0 || pac == 0)
		return (false);
	if (pab + pbc + pac == total)
		return (true);
	return (false);
}
 