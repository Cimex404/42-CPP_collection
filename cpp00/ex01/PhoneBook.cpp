/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:55:06 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/21 11:19:18 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contacts.hpp"

static std::string	truncate(std::string str)
{
	if (str.length() > 10)
		return(str.substr(0, 9) + ".");
	return (str);
}

std::string	PhoneBook::process_input(std::string prompt)
{
	std::string result;

	std::cout << prompt;
	while (getline(std::cin, result))
	{
		if (result.length() <= 0)
		{
			std::cout << "Input cannot be empty.\n" << prompt;
			continue;
		}
		return (result);
	}
	std::cout << "\nInput not processed correctly. Exiting" << std::endl;
	exit (1);
}

void	PhoneBook::add_phonebook()
{
	std::string	first;
	std::string	last;
	std::string	nick;
	std::string	phone;
	std::string	secret;

	curr_contact %= 8;
	if (max_contacts < 8)
		max_contacts ++;
	first = process_input("Enter First name: ");
	last = process_input("Enter Last name: ");
	nick = process_input("Enter Nickname: ");
	phone = process_input("Enter Phone number: ");
	secret = process_input("Enter Darkest secret: ");
	std::cout << std::endl;
	contact[curr_contact].set_contract(first, last, nick, phone, secret);
	curr_contact ++;
}

void	PhoneBook::search_phonebook()
{
	int		i;
	int		index;

	if (max_contacts == 0)
	{
		std::cout << "Phonebook is empty!\n" << std::endl;
		return;
	}
	std::cout 	<< "|" << std::setw(10) << "Index"
				<< "|" << std::setw(10) << "First name"
				<< "|" << std::setw(10) << "Last name"
				<< "|" << std::setw(10) << "Nickname"
				<< "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (i = 0; i < max_contacts; i++)
	{
		std::cout	<< "|" << std::setw(10) << i
					<< "|" << std::setw(10) << truncate(contact[i].get_first())
					<< "|" << std::setw(10) << truncate(contact[i].get_last())
					<< "|" << std::setw(10) << truncate(contact[i].get_nick())
					<< "|" << std::endl;
	}
	std::cout << std::endl;
	search_contact();
}

void	PhoneBook::search_contact()
{
	int			index;
	std::string	input;

	std::cout << "Show details of index: ";
	if (getline(std::cin, input))
	{
		try
		{
			index = stoi(input);
			if (index >= 0 && index < max_contacts)
			{
				std::cout << "\nFirst name:\t" << contact[index].get_first() << std::endl;
				std::cout << "Last name:\t" << contact[index].get_last() << std::endl;
				std::cout << "Nickname:\t" << contact[index].get_nick() << std::endl;
				std::cout << "Phone number:\t" << contact[index].get_phone() << std::endl;
				std::cout << "Darkest Secret:\t" << contact[index].get_secret() << "\n" << std::endl;
			}
			else
				std::cout << "Invalid index!\n" << std::endl;
		}
		catch(...)
		{
			std::cout << "Invalid index!\n" << std::endl;
		}
	}
	else
		std::cout << "No index given...\n" << std::endl;
}

//		Phonebook management
void	PhoneBook::manage_phonebook()
{
	std::string input;

	if (!getline(std::cin, input))
	{
		std::cout << "\nPhonebook encountered EOF. Exiting..." << std::endl;
		exit (1);
	}
	else
	{
		std::cout << std::endl;
		if (input == "ADD")
			add_phonebook();
		else if (input == "SEARCH")
			search_phonebook();
		else if (input == "EXIT")
		{
			std::cout << "Exiting phonebook..." << std::endl;
			exit(0);
		}
		else
			std::cout << "Invalid input! Try again..." << std::endl;
	}
}
