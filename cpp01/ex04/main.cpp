/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:27:40 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/20 12:16:22 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	main(int ac, char **av)
{
	std::string		filename;
	std::string		s1;
	std::string		s2;

	if (ac != 4)
	{
		std::cerr << "Invalid number of arguments!" << "\n\t<filename> <s1> <s2>" << std::endl;
		return (1);
	}
	filename = av[1];
	s1 = av[2];
	s2 = av[3];

	replace_string_in_file(filename, filename + ".replace", s1, s2);
	return (0);
}