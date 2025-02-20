/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:37:46 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/20 11:13:52 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//	Contructor
Weapon::Weapon(std::string type)
{
	this->type = type;
}

//	Set / Get Type
void	Weapon::setType(std::string type)
{
	this->type = type;
}

std::string	Weapon::getType(void)
{
	return (type);
}