/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:09:12 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/03 16:27:01 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//	Convert
void	ScalarConverter::convert(std::string input)
{
	e_datatype	type = get_datatype(input);

	switch (type)
	{
		case TYPE_CHAR:
			convert_char(input);
			break;
		case TYPE_INT:
			convert_int(input);
			break;
		case TYPE_FLOAT:
			convert_float(input);
			break;
		case TYPE_DOUBLE:
			convert_double(input);
			break;
		case TYPE_SPECIAL:
			convert_special(input);
			break;
		default:
			print_invalid(input);
	}
}