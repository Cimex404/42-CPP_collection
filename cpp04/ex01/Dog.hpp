/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:24:02 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/07 13:48:37 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

//	Libraries
# include "Animal.hpp"
# include "Brain.hpp"

//	Class
class	Dog : virtual public Animal
{
	private:
		Brain	*brain;

	public:
		Dog();
		Dog(const Dog &other);
		~Dog();
		Dog &operator=(const Dog &other);

		virtual void	makeSound() const;
		Brain			*getBrain() const;
};

#endif