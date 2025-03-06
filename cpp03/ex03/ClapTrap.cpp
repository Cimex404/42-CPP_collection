/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:11:21 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/06 10:55:11 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//	Default constructor
ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->attack_damage = 0;
	this->energie_points = 10;
	this->hit_points = 10;
	std::cout << "Default constructor called for ClapTrap: " << name << std::endl;
}

//	Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energie_points = other.energie_points;
	this->attack_damage = other.attack_damage;
	std::cout << "Copy constructor called for ClapTrap: " << name << std::endl;
}

//	Assignment operator overload
ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energie_points = other.energie_points;
		this->attack_damage = other.attack_damage;
	}
	std::cout << "Assignment operator called for ClapTrap: " << name << std::endl;
	return (*this);
}

//	Destructor
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}


//	Attack
void	ClapTrap::attack(const std::string &target)
{
	if (this->hit_points <= 0)
		std::cout << "ClapTrap " << name << " does not have enough Health to attack..." << std::endl;
	else if (this->energie_points <= 0)
		std::cout << "ClapTrap " << name << " does not have enough Energy to attack..." << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " point(s) of damage!" << std::endl;
		this->energie_points --;
	}
}

//	Take damage
void	ClapTrap::takeDamage(unsigned int amount)
{
	this->hit_points -= amount;
	if (this->hit_points <= 0)
		this->hit_points = 0;
	std::cout << "ClapTrap " << name << " was hit and recieved " << amount << " point(s) of damage!" << std::endl;
}

//	Repair
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points <= 0)
		std::cout << "ClapTrap " << name << " does not have enough Health to heal..." << std::endl;
	else if (this->energie_points <= 0)
		std::cout << "ClapTrap " << name << " does not have enough Energy to heal..." << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " healed themselves and recieved " << amount << " point(s) of health!" << std::endl;
		this->hit_points += amount;
		this->energie_points --;
	}
}

//	Status
void	ClapTrap::status(void)
{
	std::cout	<< this->name << "'s Status:\n"
				<< "\tHealth: " << this->hit_points
				<< "\tAttack: " << this->attack_damage
				<< "\tEnergy: " << this->energie_points
				<< std::endl;
}