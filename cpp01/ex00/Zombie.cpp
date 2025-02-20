/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:23:20 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/20 08:52:17 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//	Constructor
Zombie::Zombie	(std::string name)
{
	this->name = name;
}

//	Destructor
Zombie::~Zombie	(void)
{
	std::cout << name << " has been destroyed..." << std::endl;
}

//	Announces
void	Zombie::announce (void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}