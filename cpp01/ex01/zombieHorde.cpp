/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:59:39 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/24 09:43:44 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombie;
	int		i;

	if (N < 0)
	{
		std::cerr << "Number must be positive." << std::endl;
		return (NULL);
	}

	zombie = new Zombie[N];
	for (i = 0; i < N; i ++)
	{
		zombie[i].set_name(name);
		zombie[i].announce();
	}
	return (zombie);
}