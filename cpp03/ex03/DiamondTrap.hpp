/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:46:30 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/06 08:52:24 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_H
# define DIAMOND_H

//	Libraries
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

//	Class
class	DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
	private:
		std::string name;

	public:
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &other);
		~DiamondTrap();

		void attack(const std::string &target);
		void whoAmI();
		void	status();
};

#endif