/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:46:30 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/05 16:25:31 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_H
# define SCAV_H

//	Libraries
# include "ClapTrap.hpp"

//	Class
class	ScavTrap : public ClapTrap
{
	private:
		bool		gate_mode;

	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &other);

		void	guardGate();
		void	attack(const std::string &target);
		void	status();
};

#endif