/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:36:49 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/02 14:38:27 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//	Constructors
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), target("Default")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("Default", 25, 5), target(other.getTarget())
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		this->target = other.getTarget();
	return (*this);
}


//	Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	
}


//	Getter
std::string	PresidentialPardonForm::getTarget() const
{
	return (this->target);
}


//	Execute
void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!getSigned())
		throw AForm::NotSignedException();
	else if (executor.getGrade() > getExeGrade())
		throw AForm::GradeTooLowException();
	else
		std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}