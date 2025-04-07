/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:07:42 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/03 16:26:50 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//	Libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

//	Enum
enum	e_datatype
{
	TYPE_UNKNOWN,
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_SPECIAL
};

//	Class
class	ScalarConverter
{
	private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter &other) = delete;
		~ScalarConverter() = delete;
		ScalarConverter	&operator=(const ScalarConverter &other) = delete;

	public:
		static void	convert(std::string input);
};


//	Other functions
e_datatype	get_datatype(std::string input);
void		print_invalid(std::string input);
void		convert_char(std::string input);
void		convert_int(std::string input);
void		convert_float(std::string input);
void		convert_double(std::string input);
void		convert_special(std::string input);