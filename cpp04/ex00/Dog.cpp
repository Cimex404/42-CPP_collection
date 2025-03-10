/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:28:25 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/07 10:30:56 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//	Default constructor
Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Default constructor for Dog called!" << std::endl;
}

//	Copy constructor
Dog::Dog(const Dog &other) : Animal(other)
{
	this->type = other.type;
	std::cout << "Copy constructor for Dog called!" << std::endl;
}

//	Copy constructor
Dog &Dog::operator=(const Dog &other)
{
	if(this == &other)
		return (*this);
	this->type = other.type;
	std::cout << "Assignment operator overload for Dog called!" << std::endl;
	return (*this);
}

//	Deconstructor
Dog::~Dog()
{
	std::cout << "Deconstructor for Dog called!" << std::endl;
}

//	Make sound
void	Dog::makeSound() const
{
	std::cout << "Woof woof!" << std::endl;
}