/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:37:46 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/24 12:54:47 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//	Contructor
Weapon::Weapon(const std::string &type)
{
	this->type = type;
}

//	Set / Get Type
void	Weapon::setType(const std::string &type)
{
	this->type = type;
}

const std::string	&Weapon::getType(void) const
{
	return (type);
}