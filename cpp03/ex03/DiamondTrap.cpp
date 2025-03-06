/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:45:58 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/06 11:18:34 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

//	Constructor
DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	this->hit_points = FragTrap::hit_points;
	this->energie_points = ScavTrap::energie_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "Default constructor called for DiamondTrap: " << this->name << std::endl;
}

//	Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
	std::cout << "Copy constructor called for DiamondTrap: " << this->name << std::endl;
	*this = other;
}

// Assignment operator
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energie_points = other.energie_points;
		this->attack_damage = other.attack_damage;
	}
	std::cout << "Assignment operator called for DiamondTrap: " << this->name << std::endl;
	return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->name << " has been destroyed!" << std::endl;
}

// Attack
void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

// Who am I
void	DiamondTrap::whoAmI()
{
	std::cout << "Hi! My name is " << this->name << " I come from a ClapTrap called " << ClapTrap::name << std::endl;
}

//	Status
void	DiamondTrap::status(void)
{
	std::cout	<< this->name << "'s Status:\n"
				<< "\tHealth: " << this->hit_points
				<< "\tAttack: " << this->attack_damage
				<< "\tEnergy: " << this->energie_points
				<< std::endl;
}