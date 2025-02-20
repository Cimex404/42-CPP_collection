/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:33:23 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/20 11:11:43 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

//	Libraries
# include <iostream>
# include <string>

//	Class
class	Weapon
{
	private:
		std::string	type;
	
	public:
		Weapon(std::string type);
		std::string	getType();
		void		setType(std::string type);
};

#endif