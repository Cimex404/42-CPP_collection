/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:28:25 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/07 16:00:42 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//	Default constructor
Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain;
	std::cout << "Default constructor for Dog called!" << std::endl;
}

//	Copy constructor
Dog::Dog(const Dog &other) : Animal(other)
{
	this->type = other.type;
	this->brain = new Brain(*other.getBrain());
	std::cout << "Copy constructor for Dog called!" << std::endl;
}

//	Assignment operator overload
Dog &Dog::operator=(const Dog &other)
{
	if(this == &other)
		return (*this);
	if (this->brain)
		delete this->brain;
	this->type = other.type;
	this->brain = new Brain(*other.getBrain());
	std::cout << "Assignment operator overload for Dog called!" << std::endl;
	return (*this);
}

//	Deconstructor
Dog::~Dog()
{
	delete this->brain;
	std::cout << "Deconstructor for Dog called!" << std::endl;
}

//	Make sound
void	Dog::makeSound() const
{
	std::cout << "Woof woof!" << std::endl;
}


//	Getters and Setters
Brain	*Dog::getBrain() const
{
	return (brain);
}