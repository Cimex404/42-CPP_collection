/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:14:23 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/27 09:03:18 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	const Point	a;
	const Point	b(3.0f, 0.0f);
	const Point	c(0.0f, 3.0f);
	const Point	p(1.0f, 1.0f);

	if (bsp(a, b, c, p))
		std::cout << "\e[32mThe point is within the triangle!\e[0m" << std::endl;
	else
		std::cout << "\e[31mThe point is NOT within the triangle!\e[0m" << std::endl;
	return (0);
}