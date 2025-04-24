/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:12:19 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/24 17:41:56 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <vector>
#include <deque>

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: Invalid number of arguments!" << std::endl;
		return (1);
	}

	try
	{
		std::vector<size_t>	vec_input;
		std::deque<size_t>	deq_input;
		PmergeMe	vec("Vector");
		PmergeMe	deq("Deque");

		for (int i = 1; i < ac; i++)
		{
			if (std::atoi(av[i]) < 0)
				throw PmergeMe::NegativeException();
			vec_input.push_back(std::atoi(av[i]));
			deq_input.push_back(std::atoi(av[i]));
		}
		std::cout << std::endl;
		vec.sort(vec_input);
		deq.sort(deq_input);
	}
	catch (std::exception const &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}