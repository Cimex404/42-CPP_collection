/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:18:12 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/20 09:28:09 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str	= "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Adress of string\t" << &str << std::endl;
	std::cout << "Adress of stringPTR\t" << stringPTR << std::endl;
	std::cout << "Adress of stringREF\t" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of string\t\t" << str << std::endl;
	std::cout << "Value of stringPTR\t" << *stringPTR << std::endl;
	std::cout << "Value of stringREF\t" << stringREF << std::endl;

	return (0);
}