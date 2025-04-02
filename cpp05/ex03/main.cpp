/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 08:44:44 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/02 10:45:55 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	{
		std::cout << "\n\tFaulty Form Creation" << std::endl;
		Intern		unimportantIntern;
		AForm		*someForm;

		someForm = unimportantIntern.makeForm("non-existant form", "Faulty");
		someForm = unimportantIntern.makeForm("random form", "Failure");
	}
	{
		std::cout << "\n\tRobotomyRequestForm" << std::endl;
		Intern		unimportantIntern;
		Bureaucrat	bob("Bob", 20);
		AForm		*someForm;
		int			i = 0;

		someForm = unimportantIntern.makeForm("robotomy request", "Frank");
		bob.signForm(*someForm);
		while (i++ < 4)
			bob.executeForm(*someForm);
		bob.signForm(*someForm);;
		delete someForm;
	}
	return (0);
}