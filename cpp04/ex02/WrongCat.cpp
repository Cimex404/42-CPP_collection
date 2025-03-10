/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:28:25 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/07 10:25:22 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//	Default constructor
WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "Default constructor for WrongCat called!" << std::endl;
}

//	Copy constructor
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	this->type = other.type;
	std::cout << "Copy constructor for WrongCat called!" << std::endl;
}

//	Copy constructor
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if(this == &other)
		return (*this);
	this->type = other.type;
	std::cout << "Assignment operator overload for WrongCat called!" << std::endl;
	return (*this);
}

//	Deconstructor
WrongCat::~WrongCat()
{
	std::cout << "Deconstructor for WrongCat called!" << std::endl;
}

//	Make sound
void	WrongCat::makeSound() const
{
	std::cout << "Moo moo!" << std::endl;
}