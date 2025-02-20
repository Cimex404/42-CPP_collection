/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:56:11 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/20 09:07:08 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

//	Libraries
# include <iostream>
# include <string>

//	Class
class Zombie
{
	private:
		std::string	name;
	
	public:
		void	set_name(std::string name);
		void	announce();
		Zombie();
		~Zombie();
};

//	Functions
Zombie	*zombieHorde(int N, std::string name);

#endif