/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 08:34:31 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/02 08:56:17 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//	Constructors
Bureaucrat::Bureaucrat() : name("Default"), grade(1)
{

}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw GradeTooHighException();
	else if (grade < 1)
		throw GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()), grade(other.getGrade())
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->grade = other.getGrade();
	return (*this);
}

//	Destructor
Bureaucrat::~Bureaucrat()
{

}


//	Getters
std::string	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}


//	Incr -/ Decrement
void	Bureaucrat::incrementGrade()
{
	if (this->grade-1 < 1)
		throw GradeTooLowException();
	else
		this->grade --;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade+1 > 150)
		throw GradeTooHighException();
	else
		this->grade ++;
}


//	Members
void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch(std::exception &e)
	{
		std::cerr << getName() << " could not sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm &form) const
{
	try
	{
		form.execute(*this);
	}
	catch(std::exception &e)
	{
		std::cerr << getName() << " could not execute " << form.getName() << " because " << e.what() << std::endl;
	}
	
}


//	Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}


//	Ostream override
std::ostream	&operator<<(std::ostream &os, Bureaucrat const &bureau)
{
	os << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << std::endl;
	return (os);
}