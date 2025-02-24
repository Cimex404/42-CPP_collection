/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:18:12 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/24 10:59:41 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str	= "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Adress of string\t\t" << &str << std::endl;
	std::cout << "Adress held by stringPTR\t" << stringPTR << std::endl;
	std::cout << "Adress held by stringREF\t" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of string\t\t\t" << str << std::endl;
	std::cout << "Value pointed to by stringPTR\t" << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF\t" << stringREF << std::endl;

	return (0);
}