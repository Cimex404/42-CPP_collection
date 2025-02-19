/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:41:06 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/19 16:41:09 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

//		Library	(Unimportant, but my compiler doesn't like it, when I don't include this ¯\_(ツ)_/¯)
#include <string>

//		Conatct class
class	Contacts
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_nbr;
		std::string	darkest_secret;
	
	public:
		std::string	get_first();
		std::string	get_last();
		std::string	get_nick();
		std::string	get_phone();
		std::string	get_secret();
		void		set_contract(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
};

#endif
