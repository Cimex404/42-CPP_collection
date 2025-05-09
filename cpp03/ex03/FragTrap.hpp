/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:46:30 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/06 14:19:13 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_H
# define FRAG_H

//	Libraries
# include "ClapTrap.hpp"

//	Class
class	FragTrap : virtual public ClapTrap
{
	private:
		std::string	name;

	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		~FragTrap();
		FragTrap	&operator=(const FragTrap &other);

		void	highFiveGuys();
		void	attack(const std::string &target);
		void	status();
};

#endif