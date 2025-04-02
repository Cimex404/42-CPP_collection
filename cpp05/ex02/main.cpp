/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 08:44:44 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/02 10:45:54 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	{
		std::cout << "\n\tShrubberyCreationForm" << std::endl;
		Bureaucrat				frank("Frank", 150);
		Bureaucrat				bob("Bob", 20);
		ShrubberyCreationForm	tree("Tree");

		frank.signForm(tree);
		bob.signForm(tree);
		frank.executeForm(tree);
		bob.executeForm(tree);
		bob.signForm(tree);
		frank.signForm(tree);
		std::cout << tree;
	}
	{
		std::cout << "\n\tRobotomyRequestForm" << std::endl;
		Bureaucrat				frank("Frank", 150);
		Bureaucrat				bob("Bob", 20);
		RobotomyRequestForm		robot("Robot");
		int						i = 0;

		frank.signForm(robot);
		bob.signForm(robot);
		frank.executeForm(robot);
		while (i++ < 10)
			bob.executeForm(robot);
		bob.signForm(robot);
		frank.signForm(robot);
		std::cout << robot;
	}
	{
		std::cout << "\n\tPresidentialPardonForm" << std::endl;
		Bureaucrat				frank("Frank", 150);
		Bureaucrat				bob("Bob", 20);
		Bureaucrat				president("Zaphod Beeblebrox", 1);
		PresidentialPardonForm	criminal("Criminal");

		frank.signForm(criminal);
		bob.signForm(criminal);
		frank.executeForm(criminal);
		bob.executeForm(criminal);
		president.executeForm(criminal);
		bob.signForm(criminal);
		frank.signForm(criminal);
		std::cout << criminal;
	}
	return (0);
}