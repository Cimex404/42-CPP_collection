/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:04:11 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/07 17:13:25 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//	Default constructor
Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		setIdea(i, "");
	std::cout << "Default constructor for Brain called!" << std::endl;
}

//	Copy constructor
Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
		setIdea(i, other.getIdea(i));
	std::cout << "Copy constructor for Brain called!" << std::endl;
}

//	Copy constructor
Brain &Brain::operator=(const Brain &other)
{
	if(this == &other)
		return (*this);
	for (int i = 0; i < 100; i++)
		setIdea(i, other.getIdea(i));
	std::cout << "Assignment operator overload for Brain called!" << std::endl;
	return (*this);
}

//	Deconstructor
Brain::~Brain()
{
	std::cout << "Deconstructor for Brain called!" << std::endl;
}


//	Getters and Setters
std::string	Brain::getIdea(int i) const
{
	if (!ideas[i].empty() > 0 && (i >= 0 && i <= 99))
		return (ideas[i]);
	return ("No thoughts here...");
}

void	Brain::setIdea(int i, std::string idea)
{
	if (i >= 0 && i <= 99)
		ideas[i] = idea;
	else
		std::cout << "Idea index out of range" << std::endl;
}