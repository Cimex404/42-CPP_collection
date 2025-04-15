/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:12:15 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/14 15:01:36 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//	Constructor
Span::Span()
{
	this->N = 42;
}

Span::Span(unsigned int N)
{
	this->N = N;
}

Span::Span(const Span &other)
{
	this->N = other.N;
	this->vec = other.vec;
}


//	Assignment operator overload
Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->N = other.N;
		this->vec = other.vec;
	}
	return (*this);
}


//	Destructor
Span::~Span()
{
}


//	Methods
void	Span::addNumber(int nmb)
{
	if (this->vec.size() >= this->N)
		throw LimitException();
	this->vec.push_back(nmb);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->vec.size() + std::distance(begin, end) > this->N)
		throw LimitException();
	this->vec.insert(this->vec.end(), begin, end);
}

int	Span::longestSpan()
{
	if (this->vec.empty() || this->vec.size() < 2)
		throw EmptyListException();
	
	int	max_nmb = *std::max_element(this->vec.begin(), this->vec.end());
	int	min_nmb = *std::min_element(this->vec.begin(), this->vec.end());
	return (max_nmb - min_nmb);
}

int	Span::shortestSpan()
{
	if (this->vec.empty() || this->vec.size() < 2)
		throw EmptyListException();

	std::sort(this->vec.begin(), this->vec.end());
	int	span = this->vec[1] - this->vec[0];
	for (size_t i = 1; i < this->vec.size() - 1; i++)
	{
		if (span > (this->vec[i + 1] - this->vec[i]))
			span = this->vec[i + 1] - this->vec[i];
	}
	return (span);
}


//	Exception
const char	*Span::EmptyListException::what() const throw()
{
	return ("List has too few entries to get a span.");
}

const char	*Span::LimitException::what() const throw()
{
	return ("List can't hold any more entries.");
}