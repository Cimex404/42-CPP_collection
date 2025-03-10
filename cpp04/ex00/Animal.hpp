/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:24:02 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/07 10:30:53 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

//	Libraries
# include <iostream>
# include <string>

//	Class
class	Animal
{
	protected:
		std::string	type;
	
	public:
		Animal();
		Animal(const Animal &other);
		virtual ~Animal();
		Animal &operator=(const Animal &other);

		virtual void		makeSound() const;
		std::string			getType() const;
};

#endif