/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:24:16 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/07 10:41:51 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Libraries
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


//	Generate
static Base	*generate()
{
	int									rand_nmb;
	std::random_device					rd;
	std::mt19937						gen(rd());
	std::uniform_int_distribution<int>	dist(0, 2);
	
	rand_nmb = dist(gen);
	switch (rand_nmb)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (NULL);
	}
}


//	Identify
static void	identify(Base *p)
{
	if (!p)
	{
		std::cout << "Is NULL" << std::endl;
		return;
	}

	if (dynamic_cast<A*>(p))
		std::cout << "Is type 'A'" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Is type 'B'" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Is type 'C'" << std::endl;
	else
		std::cout << "Is unknown" << std::endl;
}

static void	identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Is type 'A'" << std::endl;
	}
	catch(...)
	{
		try
		{
			B	&b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "Is type 'B'" << std::endl;
		}
		catch(...)
		{
			try
			{
				C	&c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "Is type 'C'" << std::endl;
			}
			catch(...)
			{
				std::cout << "Is unknown" << std::endl;
			}
		}
	}
}


//	Main
int	main()
{
	Base	*base;

	std::cout << "\033[35m";
	for (int i = 0; i < 10; i++)
	{
		base = generate();
		identify(base);
		if (base)
		{
			identify(*base);
			delete base;
		}
		else
			std::cout << "Is NULL" << std::endl;
		std::cout << "------------------------" << std::endl;
	}
	std::cout << "\033[0m";
	return (0);
}
