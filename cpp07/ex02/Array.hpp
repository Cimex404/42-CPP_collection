/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:06:41 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/08 10:25:13 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//	Libraries
#include <iostream>
#include <string>

//	Templates
template <typename T>
class	Array
{
	private:
		T		*arr;
		size_t	len;

	public:
		Array();
		Array(unsigned int n);
		Array(Array &other);
		~Array();

		Array<T>	&operator=(Array &other);
		T			&operator[](unsigned int index);

		size_t	size() const;
	
		//	Exceptions
		class	InvalidIndexException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};