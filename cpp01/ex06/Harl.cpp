/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:45:27 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/20 14:02:02 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//	Private methods
void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << 	"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! "
					"If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << 	"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started "
					"working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

//	Public complain method
void	Harl::complain(std::string level)
{
	std::string	mode[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void 		(Harl::*func[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int			i;
	int			index = -1;

	for (i = 0; i < 4; i ++)
	{
		if (mode[i] == level)
			index = i;
	}
	switch(index)
	{
		case 0:
			(this->*func[0])();
		case 1:
			(this->*func[1])();
		case 2:
			(this->*func[2])();
		case 3:
			(this->*func[3])();
			break;
		default:
			std::cout << "[Probably complaining about insignificant problems]" << std::endl;
			break;
	}
}
