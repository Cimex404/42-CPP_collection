/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_string.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:36:34 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/20 12:28:41 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	replace_string_in_file(std::string input_file, std::string output_file, std::string s1, std::string s2)
{
	std::ifstream	in_file(input_file);
	std::ofstream	out_file(output_file);

	//	Open files
	if (!in_file)
	{
		std::cerr << "Could not open input file..." << std::endl;
		exit (1);
	}
	if (!out_file)
	{
		std::cerr << "Could not open output file..." << std::endl;
		in_file.close();
		exit (1);
	}
	
	//	Replacing the string
	std::string		line;
	std::string 	result;
	size_t 			pos;
	size_t			found_pos;

	while (std::getline(in_file, line))
	{
		result = "";
		pos = 0;
		found_pos = 0;

		while ((found_pos = line.find(s1, pos)) != std::string::npos)
		{
			result.append(line, pos, found_pos - pos);
			result.append(s2);
			pos = found_pos + s1.length();
		}
		result.append(line, pos, line.length() - pos);

		out_file << result << std::endl;
	}
	in_file.close();
	out_file.close();
}