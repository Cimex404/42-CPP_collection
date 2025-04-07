/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:06:46 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/03 14:52:30 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//	Preset tests
int	main()
{
	std::string	tests[] = {"-42", "nan", "42.874f", "'p'", "&", "-inf", "-inff", "2147483647", "2147483648", "42.87434573567345063745038450357863078"};

	//	Purple
	std::cout << "\033[35m";

	//	Program
	for (int i = 0; i < 10; i++)
	{
		std::cout << "-----------------------------------" << std::endl;
		ScalarConverter::convert(tests[i]);
		std::cout << "-----------------------------------" << std::endl;
	}
	
	//	White
	std::cout << "\033[0m";
	return (0);
}

//	Test yourself
// int	main(int ac, char **av)
// {
// 	//	Purple
// 	std::cout << "\033[35m";

// 	//	Program
// 	if (ac != 2)
// 		std::cerr << "\033[31mInvalid number of arguments. (expected 1)" << std::endl;
// 	else
// 		ScalarConverter::convert(av[1]);
	
// 	//	White
// 	std::cout << "\033[0m";
// 	return (0);
// }