/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:23:20 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/24 15:52:13 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//	Constructor
Zombie::Zombie(void)
{
	std::cout << "Zombie has been created..." << std::endl;
}

//	Destructor
Zombie::~Zombie(void)
{
	std::cout << name << " has been destroyed..." << std::endl;
}

//	Announces
void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

//	Name
void	Zombie::set_name(std::string name)
{
	this->name = name;
}