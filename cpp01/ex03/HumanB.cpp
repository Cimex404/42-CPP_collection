/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:37:46 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/24 15:56:46 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

//	Constructor
HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

//	Set Weapon type
void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	std::cout << name <<  " set " << weapon.getType() <<  " as their weapon." << std::endl;
}

//	Attack
void	HumanB::attack(void)
{
	if (weapon)
	    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has nothing to attack with. This was not very effective... " << std::endl;
}