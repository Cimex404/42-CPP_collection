/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversions.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:14:32 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/07 10:25:31 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static int	get_precision(std::string input)
{
	size_t	dot_pos = input.find('.');
	int		precision = input.length() -dot_pos -1;

	if (dot_pos == std::string::npos)
		return (1);
	if (input.back() == 'f')
		precision --;
	if (precision == 0)
		return (1);
	return (precision);
}

void	print_invalid(std::string input)
{
	std::cout << "Input:\t" << input << std::endl;
	std::cout << "TYPE:\tINVALID\n" << std::endl;
}

void	convert_char(std::string input)
{
	char	c;
	int		precision = get_precision(input);

	if (input.length() == 1)
		c = input[0];
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
		c = input[1];
	
	//	Print
	std::cout << "Input:\t" << input << std::endl;
	std::cout << "TYPE:\tCHAR\n" << std::endl;

	std::cout << "CHAR:\t'" << c << "'" << std::endl;
	std::cout << "INT:\t" << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(precision) << "FLOAT:\t" << static_cast<float>(c) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(precision) << "DOUBLE:\t" << static_cast<double>(c) << std::endl;
}

void	convert_int(std::string input)
{
	int	int_value;
	int	precision = get_precision(input);

	//	Convert
	try {
		int_value = std::stoi(input);}
	catch (const std::out_of_range) {
		std::cout << "Input:\t" << input << std::endl;
		std::cout << "TYPE:\tINT\n" << std::endl;
		std::cout << "Error!\t" << input << " is out of range for type: 'int'" << std::endl;
		return;
	}

	//	Print
	std::cout << "Input:\t" << input << std::endl;
	std::cout << "TYPE:\tINT\n" << std::endl;

	//	Char
	if (std::isprint(static_cast<char>(int_value)))
		std::cout << "CHAR:\t'" << static_cast<char>(int_value) << "'" << std::endl;
	else if (int_value < 0 || int_value > 255)
		std::cout << "CHAR:\tImpossible" << std::endl;
	else
		std::cout << "CHAR:\tNon-displayable" << std::endl;
	
	//	Int
	if (int_value >= INT_MIN && int_value <= INT_MAX)
		std::cout << "INT:\t" << int_value << std::endl;
	else
		std::cout << "INT:\tImpossible" << std::endl;
	
	//	Float & Dobule
	std::cout << std::fixed << std::setprecision(precision) << "FLOAT:\t" << static_cast<float>(int_value) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(precision) << "DOUBLE:\t" << static_cast<double>(int_value) << std::endl;
}

void	convert_float(std::string input)
{
	float	float_val = std::stof(input);
	int		precision = get_precision(input);

	//	Print
	std::cout << "Input:\t" << input << std::endl;
	std::cout << "TYPE:\tFLOAT\n" << std::endl;

	//	Char
	if (std::isprint(static_cast<char>(float_val)))
		std::cout << "CHAR:\t'" << static_cast<char>(float_val) << "'" << std::endl;
	else if (static_cast<int>(float_val) < 0 || static_cast<int>(float_val) > 255)
		std::cout << "CHAR:\tImpossible" << std::endl;
	else
		std::cout << "CHAR:\tNon-displayable" << std::endl;

	//	Int
	if (float_val >= INT_MIN && float_val <= INT_MAX)
		std::cout << "INT:\t" << static_cast<int>(float_val) << std::endl;
	else
		std::cout << "INT:\tImpossible" << std::endl;
	
	//	Float
	std::cout << std::fixed << std::setprecision(precision) << "FLOAT:\t" << float_val << "f" << std::endl;

	//	Double
	std::cout << std::fixed << std::setprecision(precision) << "DOUBLE:\t" << static_cast<double>(float_val) << std::endl;
}

void	convert_double(std::string input)
{
	double	double_val = std::stod(input);
	int		precision = get_precision(input);

	//	Print
	std::cout << "Input:\t" << input << std::endl;
	std::cout << "TYPE:\tDOUBLE\n" << std::endl;

	//	Char
	if (std::isprint(static_cast<char>(double_val)))
		std::cout << "CHAR:\t'" << static_cast<char>(double_val) << "'" << std::endl;
	else if (static_cast<int>(double_val) < 0 || static_cast<int>(double_val) > 255)
		std::cout << "CHAR:\tImpossible" << std::endl;
	else
		std::cout << "CHAR:\tNon-displayable" << std::endl;

	//	Int
	if (double_val >= INT_MIN && double_val <= INT_MAX)
		std::cout << "INT:\t" << static_cast<int>(double_val) << std::endl;
	else
		std::cout << "INT:\tImpossible" << std::endl;
	
	//	Float
	std::cout << std::fixed << std::setprecision(precision) << "FLOAT:\t" << static_cast<float>(double_val) << "f" << std::endl;

	//	Double
	std::cout << std::fixed << std::setprecision(precision) << "DOUBLE:\t" << double_val << std::endl;
}

void	convert_special(std::string input)
{
	//	Print
	std::cout << "Input:\t" << input << std::endl;
	std::cout << "TYPE:\tSPECIAL\n" << std::endl;

	//	Char
	std::cout << "CHAR:\tImpossible" << std::endl;

	//	Int
	std::cout << "INT:\tImpossible" << std::endl;

	//	Float
	if (input == "nanf" || input == "inff" || input == "+inff" || input == "-inff")
		std::cout << "FLOAT:\t" << input << std::endl;
	else
		std::cout << "FLOAT:\t" << input << "f" << std::endl;

	//	Double
	if (input == "nanf" || input == "inff" || input == "+inff" || input == "-inff")
		std::cout << "DOUBLE:\t" << input.substr(0, input.size()-1) << std::endl;
	else
		std::cout << "DOUBLE:\t" << input << std::endl;
}