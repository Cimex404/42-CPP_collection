/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:24:02 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/07 14:20:44 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WCAT_H
# define WCAT_H

//	Libraries
# include "WrongAnimal.hpp"

//	Class
class	WrongCat : virtual public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &other);
		~WrongCat();
		WrongCat &operator=(const WrongCat &other);

		void	makeSound() const;
};

#endif