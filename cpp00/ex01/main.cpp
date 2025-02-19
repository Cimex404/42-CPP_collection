/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:43:33 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/18 14:43:35 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	book;

	std::cout << "\nValid commands: ADD, SEARCH, EXIT\n" << std::endl;
	while (1)
	{
		std::cout << "Awaiting input: ";
		book.manage_phonebook();
	}
	return (0);
}
