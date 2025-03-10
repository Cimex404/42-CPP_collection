/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:24:02 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/07 13:48:28 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

//	Libraries
# include "Animal.hpp"
# include "Brain.hpp"

//	Class
class	Cat : virtual public Animal
{
	private:
		Brain	*brain;

	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
		Cat &operator=(const Cat &other);

		virtual void	makeSound() const;
		Brain			*getBrain() const;
};

#endif