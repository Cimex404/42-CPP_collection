/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 08:30:01 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/01 15:31:27 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//	Includes
#include <iostream>
#include <stdexcept>
#include <string>
#include "AForm.hpp"

class	AForm;

//	Class
class	Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat	&operator=(const Bureaucrat &other);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		signForm(AForm &form) const;
		void		executeForm(AForm &form) const;
		void		incrementGrade();
		void		decrementGrade();

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
};

//	Ostream override
std::ostream	&operator<<(std::ostream &os, Bureaucrat const &bureau);