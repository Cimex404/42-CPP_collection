/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:28:25 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/07 10:26:12 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//	Default constructor
Animal::Animal()
{
	this->type = "Unidentified Species";
	std::cout << "Default constructor for Animal called!" << std::endl;
}

//	Copy constructor
Animal::Animal(const Animal &other)
{
	this->type = other.type;
	std::cout << "Copy constructor for Animal called!" << std::endl;
}

//	Copy constructor
Animal &Animal::operator=(const Animal &other)
{
	if(this == &other)
		return (*this);
	this->type = other.type;
	std::cout << "Assignment operator overload for Animal called!" << std::endl;
	return (*this);
}

//	Deconstructor
Animal::~Animal()
{
	std::cout << "Deconstructor for Animal called!" << std::endl;
}

//	Getters and Setters
std::string	Animal::getType() const
{
	return (type);
}

//	Make sound
void	Animal::makeSound() const
{
	std::cout << "Unidentified animal noises!" << std::endl;
}