/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 08:44:44 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/01 11:22:57 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	//	Create faulty form
	{
		std::cout << "\n\tFaulty Form" << std::endl;
		try
		{
			Form	tax("Tax", -15, 10);
		}
		catch (std::exception &e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}

		try
		{
			Form	balance("Balance", 151, 50);
		}
		catch (std::exception &e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}

		try
		{
			Form	loan("Loan", 45, 0);
		}
		catch (std::exception &e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
	}

	//	Create functional form and << override test
	{
		std::cout << "\n\tFucntional Form" << std::endl;
		Form	tax("Tax", 90, 120);
		Form	balance("Balance", 30, 12);
		Form	loan("Loan", 80, 44);
		std::cout << tax;
		std::cout << balance;
		std::cout << loan;
	}

	//	Create functional form and signing test
	{
		std::cout << "\n\tSigning" << std::endl;
		Bureaucrat	bill("Bill", 120);
		Bureaucrat	frank("Frank", 45);
		Form		tax("Tax", 60, 99);
		std::cout << bill;
		std::cout << frank;
		std::cout << tax;

		bill.signForm(tax);
		frank.signForm(tax);
	}

	return (0);
}
