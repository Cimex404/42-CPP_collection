/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:00:37 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/07 10:40:10 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main()
{
	Data		og_data;
	Data		*result_data;

	//	Setup
	og_data.integer = 42;
	og_data.float_val = 42.42f;
	og_data.str = "This is the test string!";
	og_data.chr = 'c';

	//	Serialize and Deserialize
	result_data = Serializer::deserialize(Serializer::serialize(&og_data));

	//	Check
	std::cout << "\033[35m";
	std::cout << "OG data:\t" << &og_data << std::endl;
	std::cout << "New data:\t" << result_data << std::endl;
	std::cout << "\033[0m";
	return (0);
}