/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:59:39 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/20 09:05:49 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombie;
	int		i;

	zombie = new Zombie[N];
	for (i = 0; i < N; i ++)
	{
		zombie[i].set_name(name);
		zombie[i].announce();
	}
	return (zombie);
}