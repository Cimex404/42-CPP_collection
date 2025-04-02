/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 08:34:31 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/02 08:54:45 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//	Constructors
Form::Form() : name("Default"), sign_grade(1), exe_grade(1), is_signed(false)
{

}

Form::Form(const std::string name, int sign_grade, int exe_grade) : name(name), is_signed(false), sign_grade(sign_grade), exe_grade(exe_grade)
{
	if (sign_grade > 150 || exe_grade > 150)
		throw GradeTooHighException();
	if (sign_grade < 1 || exe_grade < 1)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : name(other.getName()), sign_grade(other.getSignGrade()), exe_grade(other.getExeGrade()), is_signed(other.getSigned())
{

}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->is_signed = other.getSigned();
	return (*this);
}

//	Destructor
Form::~Form()
{

}


//	Getters
std::string	Form::getName() const
{
	return (name);
}

int	Form::getSignGrade() const
{
	return (sign_grade);
}

int	Form::getExeGrade() const
{
	return (exe_grade);
}

bool	Form::getSigned() const
{
	return (is_signed);
}

//	Members
void	Form::beSigned(const Bureaucrat &bureau)
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


//	Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}



//	Ostream override
std::ostream	&operator<<(std::ostream &os, Form const &form)
{
	os << "Name: " << form.getName() << "\n  Is Signed: " << form.getSigned() << "\n  Sign Grade: " << form.getSignGrade() << "\n  Exe Grade: " << form.getExeGrade() << std::endl;
	return (os);
}