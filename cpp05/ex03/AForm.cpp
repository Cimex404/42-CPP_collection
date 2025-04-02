/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 08:34:31 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/02 14:37:12 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//	Constructors
AForm::AForm() : name("Default"), sign_grade(1), exe_grade(1), is_signed(false)
{

}

AForm::AForm(const std::string name, int sign_grade, int exe_grade) : name(name), is_signed(false), sign_grade(sign_grade), exe_grade(exe_grade)
{
	if (sign_grade > 150 || exe_grade > 150)
		throw GradeTooHighException();
	if (sign_grade < 1 || exe_grade < 1)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.getName()), sign_grade(other.getSignGrade()), exe_grade(other.getExeGrade()), is_signed(other.getSigned())
{

}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->is_signed = other.getSigned();
	return (*this);
}

//	Destructor
AForm::~AForm()
{

}


//	Getters
std::string	AForm::getName() const
{
	return (name);
}

int	AForm::getSignGrade() const
{
	return (sign_grade);
}

int	AForm::getExeGrade() const
{
	return (exe_grade);
}

bool	AForm::getSigned() const
{
	return (is_signed);
}

//	Members
void	AForm::beSigned(const Bureaucrat &bureau)
{
	if (!is_signed)
	{
		if (sign_grade >= bureau.getGrade())
		{
			is_signed = true;
			std::cout << bureau.getName() << " signed " << name << "." << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		std::cout << "Form: " << name << " has already been signed." << std::endl;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	(void)executor;
}


//	Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char *AForm::SignedException::what() const throw()
{
	return ("Form was already signed!");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed!");
}



//	Ostream override
std::ostream	&operator<<(std::ostream &os, AForm const &form)
{
	os << "  Name: " << form.getName() << "\n  Is Signed: " << form.getSigned() << "\n  Sign Grade: " << form.getSignGrade() << "\n  Exe Grade: " << form.getExeGrade() << std::endl;
	return (os);
}