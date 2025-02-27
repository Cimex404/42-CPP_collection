/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:41:58 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/27 08:35:26 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//	Default constructor
Point::Point(void): x(0), y(0) {}

//	Asignment constructor
Point::Point(const float x, const float y): x(x), y(y) {}

//	Copy constructor
Point::Point(const Point &point): x(point.x), y(point.y) {}

//	Destructor
Point::~Point() {}


//	Getters
const float	Point::get_x(void)
{
	return (this->x.toFloat());
}

const float	Point::get_y(void)
{
	return (this->y.toFloat());
}