/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:45:58 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/06 10:54:33 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

//	Default constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->attack_damage = 30;
	this->energie_points = 100;
	this->hit_points = 100;
	std::cout << "Default constructor called for FragTrap: " << name << std::endl;
}

//	Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "Copy constructor called for ScavTrap: " << name << std::endl;
}

//	Assignment operator
FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energie_points = other.energie_points;
		this->attack_damage = other.attack_damage;
	}
	std::cout << "Assignment operator called for FragTrap: " << name << std::endl;
	return (*this);
}

//	Destructor
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << name << " has been destroyed!" << std::endl;
}


//	Attack
void	FragTrap::attack(const std::string &target)
{
	if (this->hit_points <= 0)
		std::cout << "FragTrap " << name << " does not have enough Health to attack..." << std::endl;
	else if (this->energie_points <= 0)
		std::cout << "FragTrap " << name << " does not have enough Energy to attack..." << std::endl;
	else
	{
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attack_damage << " point(s) of damage!" << std::endl;
		this->energie_points --;
	}
}

//	Highfive guys
void	FragTrap::highFiveGuys(void)
{
	if (this->hit_points > 0)
		std::cout << name << " gave their commarades a heartfelt high five!" << std::endl;
	else
		std::cout << name << " is dead and can't give their commarades a heartfelt high five! :(" << std::endl;
}

//	Status
void	FragTrap::status(void)
{
	std::cout	<< name << "'s Status:\n"
				<< "\tHealth: " << hit_points
				<< "\tAttack: " << attack_damage
				<< "\tEnergy: " << energie_points
				<< std::endl;
}