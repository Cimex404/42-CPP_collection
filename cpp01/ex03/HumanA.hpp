/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:33:23 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/20 11:17:10 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

//	Libraries
# include <iostream>
# include <string>
# include "Weapon.hpp"

//	Class
class	HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;
	
	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack(void);
};

#endif