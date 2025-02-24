/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:33:23 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/24 12:54:44 by jgraf            ###   ########.fr       */
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
		Weapon(const std::string &type);
		const std::string	&getType()	const;
		void				setType(const std::string &type);
};

#endif