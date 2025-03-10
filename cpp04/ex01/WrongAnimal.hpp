/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:24:02 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/07 14:20:37 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WANIMAL_H
# define WANIMAL_H

//	Libraries
# include <iostream>
# include <string>

//	Class
class	WrongAnimal
{
	protected:
		std::string	type;
	
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		virtual ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &other);

		void		makeSound() const;
		std::string	getType() const;
};

#endif