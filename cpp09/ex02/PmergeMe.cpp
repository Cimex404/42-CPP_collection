/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:12:06 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/28 11:30:15 by jgraf            ###   ########.fr       */
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


//	Exceptions
const char	*PmergeMe::NegativeException::what() const throw()
{
	return ("Negative numbers are forbidden!");
}

const char	*PmergeMe::InvalidInputException::what() const throw()
{
	return ("Input contains invalid characters!");
}