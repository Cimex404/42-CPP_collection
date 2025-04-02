/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 08:44:44 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/02 08:52:22 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	//	Create faulty bureaucrat
	{
		std::cout << "\n\tFaulty Bureaucrat" << std::endl;
		try
		{
			Bureaucrat	steve("Steve", -15);
		}
		catch (std::exception &e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}

		try
		{
			Bureaucrat	bob("Bob", 151);
		}
		catch (std::exception &e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}

		try
		{
			Bureaucrat	frank("Frank", 0);
		}
		catch (std::exception &e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
	}

	//	Create functional bureaucrat and << override test
	{
		std::cout << "\n\tFunctional Bureaucrat" << std::endl;
		Bureaucrat	steve("Steve", 15);
		Bureaucrat	bob("Bob", 70);
		Bureaucrat	frank("Frank", 135);
		std::cout << steve;
		std::cout << bob;
		std::cout << frank;
	}

	//	Create functional bureaucrat and << override test
	{
		std::cout << "\n\tIn -/ Decrement Test" << std::endl;
		Bureaucrat	steve("Steve", 15);
		Bureaucrat	frank("Frank", 145);
		std::cout << steve;
		std::cout << frank;

		while (steve.getGrade() > -10)
		{
			try
			{
				steve.incrementGrade();
				std::cout << steve;
			}
			catch (std::exception &e)
			{
				std::cerr << "Caught exception: " << e.what() << std::endl;
				break;
			}
		}

		while (frank.getGrade() < 160)
		{
			try
			{
				frank.decrementGrade();
				std::cout << frank;
			}
			catch (std::exception &e)
			{
				std::cerr << "Caught exception: " << e.what() << std::endl;
				break;
			}
		}
	}
	return (0);
}