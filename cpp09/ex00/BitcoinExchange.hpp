/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:09:52 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/18 10:11:54 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <map>

//	Class
class BitcoinExchange
{
	private:
		std::map<std::string, float> data;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange	&operator=(const BitcoinExchange &other);
	
		void		process(char *in_file);
		void		fill_database();
		void		get_exchange(std::string line);
		std::string	get_closest_date(std::string date);
		bool		check_date_valid(std::string date);

		//Excpetions
		class	WrongFileException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	NumberTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	NumberTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	BadInputException : public std::exception
		{
			private:
				std::string	msg;

			public:
				BadInputException(const std::string &line);
				const char	*what() const throw();
		};

		class	NotFoundException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};