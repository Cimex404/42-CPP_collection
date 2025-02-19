/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:15:32 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/18 12:15:34 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H


//		Libraries
# include <iostream>
# include <string>
# include <iomanip>
# include "Contacts.hpp"


//		Phonebook class
class	PhoneBook
{
	public:
		PhoneBook() : curr_contact(0), max_contacts(0) {};
		Contacts	contact[8];
		void		manage_phonebook();
	
	private:
		int			curr_contact;
		int			max_contacts;
		std::string	process_input();
		void		add_phonebook();
		void		search_phonebook();
		void		search_contact();
};


#endif
