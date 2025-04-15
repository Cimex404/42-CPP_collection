/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:09:23 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/09 16:42:42 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//	Libraries
#include <iostream>
#include <string>
#include <exception>


//	Exceptions
class	NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Number not found");
		}
};


//	Templates
template <typename T>
typename T::iterator	easyfind(T &container, int nmb)
{
	typename T::iterator found = std::find(container.begin(), container.end(), nmb);
	if (found != container.end())
		return (found);
	throw NotFoundException();
}