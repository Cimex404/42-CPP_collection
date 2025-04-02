/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 08:30:01 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/01 15:16:11 by jgraf            ###   ########.fr       */
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
class	Form
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			sign_grade;
		const int			exe_grade;
	
	public:
		Form();
		Form(const std::string name, int sign_grade, int exe_grade);
		Form(const Form &other);
		Form	&operator=(const Form &other);
		~Form();

		std::string	getName() const;
		int			getSignGrade() const;
		int			getExeGrade() const;
		bool		getSigned() const;
		void		beSigned(const Bureaucrat &bureau);

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
std::ostream	&operator<<(std::ostream &os, Form const &form);