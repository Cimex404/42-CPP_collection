/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:54:20 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/24 09:44:29 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cerr << "\nInvalid number of arguments.\n\t<zombie_count> <name>\n" << std::endl;
		return (1);
	}

	Zombie	*zombie = zombieHorde(std::atoi(av[1]), av[2]);
	if (zombie == NULL)
		return (1);
	delete[] zombie;
	return (0);
}