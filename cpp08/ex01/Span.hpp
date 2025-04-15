/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:05:56 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/10 15:28:36 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//	Libraries
#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <algorithm>
#include <limits>


//	Class
class	Span
{
	private:
		unsigned int 		N;
		std::vector<int>	vec;
	
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		~Span();
		Span	&operator=(const Span &other);

		void	addNumber(int nmb);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();
	
		class	EmptyListException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	LimitException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};