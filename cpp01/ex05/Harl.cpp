/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:45:27 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/24 13:03:19 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

//	Private methods
void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << 	"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! "
					"If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << 	"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started "
					"working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

//	Public complain method
void	Harl::complain(std::string level)
{
	std::string	mode[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void 		(Harl::*func[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int			i = 0;

	while (i < 4)
	{
		if (level == mode[i])
		{
			std::cout << "[" << mode[i] << "]" << std::endl;
			(this->*func[i])();
			return;
		}
		i ++;
	}
	std::cout << "[INVALID]\nHarl had nothing to complain about. :)" << std::endl;
}
