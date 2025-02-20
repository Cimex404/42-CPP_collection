/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:33:23 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/20 11:22:58 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

//	Libraries
# include <iostream>
# include <string>
# include "Weapon.hpp"

//	Class
class	HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;
	
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon &weapon);
		void	attack(void);
};

#endif