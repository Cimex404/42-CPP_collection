/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:07:24 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/05 15:18:35 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_H
# define CLAP_H

//	Libraries
# include <iostream>
# include <string>

//	Class
class	ClapTrap
{
	protected:
		std::string	name;
		int			hit_points;
		int			attack_damage;
		int			energie_points;

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();
		ClapTrap	&operator=(const ClapTrap &other);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	status();
};


#endif