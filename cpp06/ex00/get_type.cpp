/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:36:41 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/03 16:26:14 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool	is_char(std::string input)
{
	if ((input.length() == 1 && !std::isdigit(input[0]))
	|| (input.length() == 3 && input[0] == '\'' && input[2] == '\''))
		return (true);
	return (false);
}

static bool	is_integer(std::string input)
{
	size_t	i = 0;

	if (input.length() == 0)
		return (false);
	if (input[0] == '+' || input[0] == '-')
		i ++;
	for (; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
			return (false);
	}
	return (true);
}

static bool	is_double(std::string input)
{
	size_t		i = 0;
	bool	has_decimal_point = false;

	if (input.length() == 0)
		return (false);
	if (input[0] == '+' || input[0] == '-')
		i ++;
	for (; i < input.length(); i++)
	{
		if (input[i] == '.')
		{
			if (has_decimal_point)
				return (false);
			has_decimal_point = true;
		}
		else if (!std::isdigit(input[i]))
			return (false);
	}
	return (has_decimal_point);
}

static bool	is_float(std::string input)
{
	size_t		i = 0;
	bool	has_decimal_point = false;

	if (input.length() == 0)
		return (false);
	if (input[0] == '+' || input[0] == '-')
		i ++;
	for (; i < input.length(); i++)
	{
		if (input[i] == '.')
		{
			if (has_decimal_point)
				return (false);
			has_decimal_point = true;
		}
		else if (input[i] == 'f' && i+1 == input.length())
			break;
		else if (!std::isdigit(input[i]))
			return (false);
	}
	return (has_decimal_point);
}

static bool	is_special(std::string input)
{
	std::string	special_cases[] = {"nan", "nanf", "+inf", "-inf", "+inff", "-inff"};

	for (int i = 0; i < 6; i++)
	{
		if (input == special_cases[i])
			return (true);
	}
	return (false);
}

e_datatype	get_datatype(std::string input)
{
	if (is_char(input))
		return (TYPE_CHAR);
	else if (is_integer(input))
		return (TYPE_INT);
	else if (is_double(input))
		return (TYPE_DOUBLE);
	else if (is_float(input))
		return (TYPE_FLOAT);
	else if (is_special(input))
		return (TYPE_SPECIAL);
	return (TYPE_UNKNOWN);
}