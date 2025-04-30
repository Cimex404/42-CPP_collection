/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:26:52 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/30 08:30:58 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//	Constructor
BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->data = other.data;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->data = other.data;
	return (*this);
}


//	Destructor
BitcoinExchange::~BitcoinExchange()
{

}


//	Fill Database
void	BitcoinExchange::fill_database()
{
	std::string		database = "data.csv";
	std::ifstream	file(database);
	std::string		line;
	std::string		date;

	//	Check successful opanage
	if (!file.is_open() || file.fail() || std::filesystem::is_directory(database))
	{
		if (file.is_open())
			file.close();
		throw WrongFileException();
	}

	//	Add entries to map
	while(std::getline(file, line))
	{
		if (line != "date,exchange_rate")
		{
			date = line.substr(0, line.find(","));
			this->data[date] = std::atof(line.substr(line.find(",") + 1, line.length()).c_str());
		}
	}

	//	Close file to avoid leaks
	file.close();
}


//	Get closest date
std::string BitcoinExchange::get_closest_date(std::string date)
{
	int	year = std::atoi(date.substr(0, date.find("-")).c_str());
	int	month = std::atoi(date.substr(date.find("-") + 1, date.find_last_of("-") - date.find("-") - 1).c_str());
	int	day = std::atoi(date.substr(date.find_last_of("-") + 1).c_str());

	while (year >= 2009)
	{
		while (month > 0)
		{
			while (day > 0)
			{
				std::ostringstream oss;
				oss << year << "-";
				oss << std::setw(2) << std::setfill('0') << month << "-";
				oss << std::setw(2) << std::setfill('0') << day;
				if (data.find(oss.str()) != data.end())
					return (oss.str());
				day --;
			}
			month --;
			day = 31;
		}
		year --;
		month = 12;
	}
	throw	NotFoundException();
}


//	Check valid date
bool	BitcoinExchange::check_date_valid(std::string date)
{
	int		year;
	int		month;
	int		day;
	int		days[] = {31, 28, 31, 30, 31, 30, 30, 31, 30, 31, 30, 31};

	year = std::atoi(date.substr(0, date.find("-")).c_str());
	month = std::atoi(date.substr(date.find("-") + 1, date.find_last_of("-") - date.find("-") - 1).c_str());
	day = std::atoi(date.substr(date.find_last_of("-") + 1).c_str());
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		days[1] = 29;
	if (day <= days[month-1] && month <= 12)
		return (false);
	return (true);
}


//	Exchange
void	BitcoinExchange::get_exchange(std::string line)
{
	std::string date;
	float		value;

	if (line.find("|") == std::string::npos)
		throw BadInputException(line);
	date = line.substr(0, line.find("|"));
	if (date.find(" ") != std::string::npos)
		date.erase(date.find(" "), 1);

	try
	{
		value = std::stof(line.substr(line.find("|") + 1));
	}
	catch (const std::exception &e)
	{
		throw BadInputException(line);
	}
	if (value < 0)
		throw NumberTooLowException();
	if (value > 1000)
		throw NumberTooHighException();
	if (check_date_valid(date))
		throw BadInputException(line);
	if (data.find(date) != data.end())
		std::cout << date << " => " << value * data[date] << std::endl;
	else
		std::cout << date << " => " << value * data[get_closest_date(date)] << std::endl;
}


//	Process
void	BitcoinExchange::process(char *in_file)
{
	std::ifstream	file(in_file);
	std::string		line;

	//	Check successful openage
	if (!file.is_open() || file.fail() || std::filesystem::is_directory(in_file))
	{
		if (file.is_open())
			file.close();
		throw WrongFileException();
	}

	//	Fill database
	try
	{
		fill_database();
	}
	catch(const WrongFileException &e)
	{
		file.close();
		throw WrongFileException();
	}

	//	Go line by line
	while (std::getline(file, line))
	{
		try
		{
			get_exchange(line);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	//	Close to avoid leaks
	file.close();
}


//	Exceptions
const char	*BitcoinExchange::WrongFileException::what() const throw()
{
	return ("File could not be opened!");
}

const char	*BitcoinExchange::NumberTooLowException::what() const throw()
{
	return ("Not a positive number.");
}

const char	*BitcoinExchange::NumberTooHighException::what() const throw()
{
	return ("Number is larger than 1000.");
}

const char	*BitcoinExchange::NotFoundException::what() const throw()
{
	return ("No date found.");
}

//	Bad input exception with custom message
BitcoinExchange::BadInputException::BadInputException(const std::string &line)
{
	this->msg = "Bad Input => " + line;
}

const char	*BitcoinExchange::BadInputException::what() const throw()
{
	return (this->msg.c_str());
}