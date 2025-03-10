/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:28:25 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/07 10:30:23 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//	Default constructor
Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Default constructor for Cat called!" << std::endl;
}

//	Copy constructor
Cat::Cat(const Cat &other) : Animal(other)
{
	this->type = other.type;
	std::cout << "Copy constructor for Cat called!" << std::endl;
}

//	Copy constructor
Cat &Cat::operator=(const Cat &other)
{
	if(this == &other)
		return (*this);
	this->type = other.type;
	std::cout << "Assignment operator overload for Cat called!" << std::endl;
	return (*this);
}

//	Deconstructor
Cat::~Cat()
{
	std::cout << "Deconstructor for Cat called!" << std::endl;
}

//	Make sound
void	Cat::makeSound() const
{
	std::cout << "Meow meow!" << std::endl;
}