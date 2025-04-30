/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:12:19 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/29 08:47:44 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
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
		PmergeMe			vec("Vector");
		PmergeMe			deq("Deque");

		for (int i = 1; i < ac; i++)
		{
			std::string	arg(av[i]);
			if (std::stol(av[i]) < 0)
				throw PmergeMe::NegativeException();
			if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
				throw PmergeMe::InvalidInputException();
			vec_input.push_back(std::atoi(av[i]));
			deq_input.push_back(std::atoi(av[i]));
		}
		std::cout << std::endl;
		vec.sort(vec_input, true);
		deq.sort(deq_input, false);
	}
	catch (std::exception const &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}