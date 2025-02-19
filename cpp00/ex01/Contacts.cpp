/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:41:25 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/19 13:41:27 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	Contacts::get_first()
{
	return (first_name);
}

std::string	Contacts::get_last()
{
	return (last_name);
}

std::string	Contacts::get_nick()
{
	return (nick_name);
}

std::string	Contacts::get_phone()
{
	return (phone_nbr);
}

std::string	Contacts::get_secret()
{
	return (darkest_secret);
}

void	Contacts::set_contract(std::string first, std::string last, std::string nick, std::string phone, std::string secret)
{
	this->first_name = first;
	this->last_name = last;
	this->nick_name = nick;
	this->phone_nbr = phone;
	this->darkest_secret = secret;
}