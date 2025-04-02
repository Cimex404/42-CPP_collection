/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:29:28 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/02 14:38:03 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//	Libraries
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include "AForm.hpp"

//	Class
class	PresidentialPardonForm : public AForm
{
	private:
		std::string	target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		void		execute(const Bureaucrat &executor) const;
		std::string	getTarget() const;

		class OpenFileExeption : public std::exception
		{
			public:
				const char *what() const throw();
		};
};
