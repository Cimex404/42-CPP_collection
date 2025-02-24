/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:27:40 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/24 13:00:08 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

static void	replace_string_in_file(std::string input_file, std::string s1, std::string s2)
{
	std::ifstream	in_file(input_file);

	//	Open files
	if (!in_file)
	{
		std::cerr << "Could not open input file..." << std::endl;
		exit (1);
	}
	std::ofstream	out_file(input_file + ".replace");
	if (!out_file)
	{
		std::cerr << "Could not open output file..." << std::endl;
		in_file.close();
		exit (1);
	}
	
	//	Variables used for the stirng conversion
	std::string		line = "";
	std::string 	result = "";
	std::string		file_content = "";
	size_t 			pos = 0;
	size_t			found_pos = 0;

	//	Putting the file content into a buffer
	while (std::getline(in_file, line))
	{
		file_content.append(line);
		file_content.append("\n");
	}
	file_content.pop_back();

	//	Replaceing s1 with s2
	while ((found_pos = file_content.find(s1, pos)) != std::string::npos)
	{
		result.append(file_content, pos, found_pos - pos);
		result.append(s2);
		pos = found_pos + s1.length();
	}
	result.append(file_content, pos, file_content.length() - pos);

	//	Put the result into the file
	out_file << result;

	//	Closing files
	in_file.close();
	out_file.close();
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "\nInvalid number of arguments!" << "\n\t<filename> <s1> <s2>\n" << std::endl;
		return (1);
	}

	replace_string_in_file(av[1], av[2], av[3]);
	return (0);
}