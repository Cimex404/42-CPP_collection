/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:15:53 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/09 15:18:22 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void	print_value(T value)
{
	std::cout << value << std::endl;
}

int	main(void)
{
	{
		int	arr[] = {5, 42, 41, 36, 2574, 14};
		iter(arr, 6, print_value<int>);
		std::cout << "-----------------------" << std::endl;
	}
	{
		float	arr[] = {5.75f, 42.42f, 41.654f, 36.47f, 2574.0f, 14.0987f};
		iter(arr, 6, print_value<float>);
		std::cout << "-----------------------" << std::endl;
	}
	{
		char	arr[] = {'H', 'e', 'l', 'l', 'o', '!'};
		iter(arr, 6, print_value<char>);
		std::cout << "-----------------------" << std::endl;
	}
	{
		std::string	arr[] = {"Hello", "World"};
		iter(arr, 2, print_value<std::string>);
	}
	return (0);
}
