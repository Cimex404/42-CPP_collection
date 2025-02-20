/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:25:31 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/20 08:47:34 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombie;
	
	zombie = newZombie("Heap");
	zombie->announce();
	delete zombie;

	randomChump("Stack");
	return (0);
}