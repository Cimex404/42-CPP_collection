/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:14:23 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/27 08:51:16 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed 		a;
	Fixed const	b(Fixed( 5.05f ) * Fixed( 2 ));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;
	std::cout << "Max:\t\t\t" << Fixed::max(a, b) << std::endl;
	std::cout << "Min:\t\t\t" << Fixed::min(a, b) << std::endl;
	std::cout << "Addition:\t\t" << a+b << std::endl;
	std::cout << "Subtraction:\t\t" << a-b << std::endl;
	std::cout << "Multiplication:\t\t" << a*b << std::endl;
	std::cout << "Division:\t\t" << a/b << std::endl;
	std::cout << "Clearer Division:\t" << Fixed(20)/b << std::endl;
	return (0);
}

//			Subject example main (check output)
/*int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}*/