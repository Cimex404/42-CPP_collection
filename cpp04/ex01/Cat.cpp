/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:28:25 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/07 16:00:43 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//	Default constructor
Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain;
	std::cout << "Default constructor for Cat called!" << std::endl;
}

//	Copy constructor
Cat::Cat(const Cat &other) : Animal(other)
{
	this->type = other.type;
	this->brain = new Brain(*other.getBrain());
	std::cout << "Copy constructor for Cat called!" << std::endl;
}

//	Assignment operator overload
Cat &Cat::operator=(const Cat &other)
{
	if(this == &other)
		return (*this);
	if (this->brain)
		delete this->brain;
	this->type = other.type;
	this->brain = new Brain(*other.getBrain());
	std::cout << "Assignment operator overload for Cat called!" << std::endl;
	return (*this);
}

//	Deconstructor
Cat::~Cat()
{
	delete this->brain;
	std::cout << "Deconstructor for Cat called!" << std::endl;
}

//	Make sound
void	Cat::makeSound() const
{
	std::cout << "Meow meow!" << std::endl;
}


//	Getters and Setters
Brain	*Cat::getBrain() const
{
	return (brain);
}