/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:08:29 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/14 14:49:56 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <array>

int main()
{
	try
	{
		std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7};
		std::cout << "Found: " << *easyfind(vec, 5) << std::endl;

		std::list<int> lst = {0, 1, 2, 3};
		std::cout << "Found: " << *easyfind(lst, 3) << std::endl;

		std::deque<int> dque = {-62, 84, 10, 9, 333};
		std::cout << "Found: " << *easyfind(dque, -62) << std::endl;

		std::array<int, 3> arr = {64917, -7197, 10000};
		std::cout << "Found: " << *easyfind(arr, 10000) << std::endl;

		easyfind(vec, 42);
	}
	catch (const NotFoundException &e)
	{
		std::cerr << "Failed, because " << e.what() << "!" << std::endl;
	}
	return (0);
}