/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:05:30 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/08 11:16:43 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int main()
{
	{
		std::cout << "\tEmpty Array" << std::endl;
		Array<int>	a;

		try
		{
			a[0] = 42;
		}
		catch (const Array<int>::InvalidIndexException &e)
		{
			std::cerr << "Failed because: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\tArray of size 20" << std::endl;
		Array<int>	b(20);

		for (int i = 0; i < 20; i++)
			b[i] = i;
		for (int i = 0; i < 20; i++)
			std::cout << b[i] << std::endl;
	}
	{
		std::cout << "\tCopy array" << std::endl;
		Array<int>	c(10);
		Array<int>	d(10);

		for (int i = 0; i < 10; i++)
			c[i] = i;
		
		d = c;
		Array<int>	e(c);
		c[9] = -42;

		for (int i = 5; i < 10; i++)
			d[i] = 42;
		for (int i = 0; i < 10; i++)
			std::cout << "C:  " << c[i] << "\tD:  " << d[i] << "\tE:  " << e[i] << std::endl;
	}
}