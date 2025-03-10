/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:04:34 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/07 10:28:53 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

//	Libraries
# include <iostream>
# include <string>

//	Class
class	Brain
{
	private:
		std::string	ideas[100];
	
	public:
		Brain();
		Brain(const Brain &other);
		~Brain();
		Brain &operator=(const Brain &other);
	
		void		setIdea(int i, std::string idea);
		std::string	getIdea(int i) const;
};

#endif