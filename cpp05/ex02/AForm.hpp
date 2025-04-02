/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 08:30:01 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/02 14:37:04 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//	Includes
#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class	Bureaucrat;

//	Class
class	AForm
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			sign_grade;
		const int			exe_grade;
	
	public:
		AForm();
		AForm(const std::string name, int sign_grade, int exe_grade);
		AForm(const AForm &other);
		AForm	&operator=(const AForm &other);
		virtual ~AForm();

		virtual std::string	getName() const;
		virtual int			getSignGrade() const;
		virtual int			getExeGrade() const;
		virtual bool		getSigned() const;
		virtual void		beSigned(const Bureaucrat &bureau);
		virtual void		execute(const Bureaucrat &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class SignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class NotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

//	Ostream override
std::ostream	&operator<<(std::ostream &os, AForm const &form);