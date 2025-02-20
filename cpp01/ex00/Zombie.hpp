/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:18:58 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/20 08:44:47 by jgraf            ###   ########.fr       */
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
		void	announce();
		Zombie(std::string name);
		~Zombie();
};

//	Functions
Zombie	*newZombie(std::string name);
void	randomChump(std::string name);


#endif