/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:29:23 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/02 09:23:54 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//	Constructors
Intern::Intern()
{

}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern	&Intern::operator=(const Intern &other)
{
	return (*this);
}


//	Destructor
Intern::~Intern()
{

}


//	Make Form
static AForm	*makePresidentForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobotForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubberyForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

// Public Methods
AForm	*Intern::makeForm(std::string form_name, std::string form_target)
{
	AForm *(*forms_ptr[])(const std::string target) = {&makePresidentForm, &makeRobotForm, &makeShrubberyForm};
	std::string form_list[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (form_name == form_list[i])
		{
			std::cout << "Intern creates " << form_name << " form." << std::endl;
			return (forms_ptr[i](form_target));
		}
	}
	std::cout << "Intern failed to create a form called '" << form_name << "'" << std::endl;
	return (NULL);
}