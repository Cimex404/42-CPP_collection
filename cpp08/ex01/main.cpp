/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:04:30 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/15 14:02:26 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	{
		std::cout << "\t---Subject Main---" << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\n\t---Limit test---" << std::endl;
		Span sp = Span(3);

		try
		{
			sp.addNumber(2);
			sp.addNumber(7);
			sp.addNumber(17);
			sp.addNumber(20);
		}
		catch(const Span::LimitException &e)
		{
			std::cerr << "Failed beacause " << e.what() << std::endl;
		}

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\n\t---Empty List test---" << std::endl;
		Span sp = Span(5);

		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const Span::EmptyListException &e)
		{
			std::cerr << "Failed beacause " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\t---Add multiple vectors to list---" << std::endl;
		std::vector<int> v1;
		std::vector<int> v2;
		Span og = Span(5);

		v1.push_back(0);
		v1.push_back(1);
		v2.push_back(5);
		v2.push_back(10);
		v2.push_back(16);
		og.addNumber(v1.begin(), v1.end());
		og.addNumber(v2.begin(), v2.end());
		std::cout << og.shortestSpan() << std::endl;
		std::cout << og.longestSpan() << std::endl;
	}
	{
		srand(static_cast<unsigned int>(time(0)));
		std::cout << "\n\t---Big Random Test---" << std::endl;
		Span				sp(10000);
		std::vector<int>	v;
		for (int i = 0; i < 10000; i++)
		{
			v.push_back(rand() % INT_MAX);
			sp.addNumber(v.begin(), v.end());
			v.clear();
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return (0);
}