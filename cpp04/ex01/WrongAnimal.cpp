/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:28:25 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/07 10:29:17 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//	Default constructor
WrongAnimal::WrongAnimal()
{
	this->type = "Wrong Species";
	std::cout << "Default constructor for WrongAnimal called!" << std::endl;
}

//	Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->type = other.type;
	std::cout << "Copy constructor for WrongAnimal called!" << std::endl;
}

//	Copy constructor
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if(this == &other)
		return (*this);
	this->type = other.type;
	std::cout << "Assignment operator overload for WrongAnimal called!" << std::endl;
	return (*this);
}

//	Deconstructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "Deconstructor for WrongAnimal called!" << std::endl;
}

//	Getters and Setters
std::string	WrongAnimal::getType() const
{
	return (type);
}

//	Make sound
void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong animal noises!" << std::endl;
}