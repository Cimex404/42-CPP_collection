/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:12:06 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/24 17:32:38 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//	Constructors
PmergeMe::PmergeMe(std::string name)
{
	this->container_type = name;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->container_type = other.container_type;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
		this->container_type = other.container_type;
	return (*this);
}


//	Destructor
PmergeMe::~PmergeMe()
{

}

// Generate Jacobsthal sequence
std::vector<size_t>	PmergeMe::generate_jacobsthal(size_t n)
{
	std::vector<size_t>	jacobsthal;
	if (n == 0)
		return (jacobsthal);
	jacobsthal.push_back(0);
	if (n == 1)
		return (jacobsthal);
	jacobsthal.push_back(1);
	for (size_t i = 2; i < n; ++i)
	{
		size_t	value = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		jacobsthal.push_back(value);
	}
	return (jacobsthal);
}


//	Exceptions
const char	*PmergeMe::NegativeException::what() const throw()
{
	return ("Negative numbers are forbidden!");
}