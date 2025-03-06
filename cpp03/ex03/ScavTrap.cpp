/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:45:58 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/06 14:58:52 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

//	Default constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name), name(name)
{
	this->attack_damage = 20;
	this->energie_points = 50;
	this->hit_points = 100;
	this->gate_mode = false;
	std::cout << "Default constructor called for ScavTrap: " << name << std::endl;
}

//	Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "Copy constructor called for ScavTrap: " << name << std::endl;
}

//	Assignment operator
ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energie_points = other.energie_points;
		this->attack_damage = other.attack_damage;
	}
	std::cout << "Assignment operator called for ScavTrap: " << name << std::endl;
	return (*this);
}

//	Destructor
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << name << " has been destroyed!" << std::endl;
}


//	Attack
void	ScavTrap::attack(const std::string &target)
{
	if (this->hit_points <= 0)
		std::cout << "ScavTrap " << name << " does not have enough Health to attack..." << std::endl;
	else if (this->energie_points <= 0)
		std::cout << "ScavTrap " << name << " does not have enough Energy to attack..." << std::endl;
	else
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " point(s) of damage!" << std::endl;
		this->energie_points --;
	}
}

//	Guard Gate
void	ScavTrap::guardGate()
{
	if (this->hit_points <= 0)
		std::cout << name << " does not have enough Health to change their guarding mode..." << std::endl;
	else
	{
		this->gate_mode = !this->gate_mode;
		if (this->gate_mode)
			std::cout << name << " is now guarding the gate!" << std::endl;
		else
			std::cout << name << " is not longer guarding the gate!" << std::endl;
	}
}

//	Random Getter
int	ScavTrap::get_EP()
{
	return (energie_points);
}

//	Status
void	ScavTrap::status(void)
{
	std::cout	<< this->name << "'s Status:\n"
				<< "\tHealth: " << this->hit_points
				<< "\tAttack: " << this->attack_damage
				<< "\tEnergy: " << this->energie_points
				<< std::endl;
}