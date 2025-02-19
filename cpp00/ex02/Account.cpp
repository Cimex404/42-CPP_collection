/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:12:59 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/18 16:13:01 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//	Constructor
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout 	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

//	Destructor
Account::~Account()
{
	_displayTimestamp();
	std::cout 	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
}

//	Getters for global account information
int Account::getNbAccounts()		{ return (_nbAccounts);			};
int Account::getTotalAmount()		{ return (_totalAmount);		};
int Account::getNbDeposits()		{ return (_totalNbDeposits);	};
int Account::getNbWithdrawals()		{ return (_totalNbWithdrawals);	};
int Account::checkAmount() const	{ return (_amount);				};

//	Timestamps [yyyymmdd_hhmmss]
void Account::_displayTimestamp()
{
	std::time_t now = std::time(nullptr);
	std::tm *ltm = std::localtime(&now);
	std::cout 	<< "["
				<< 1900 + ltm->tm_year
				<< std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon
				<< std::setw(2) << std::setfill('0') << ltm->tm_mday << "_"
				<< std::setw(2) << std::setfill('0') << ltm->tm_hour
				<< std::setw(2) << std::setfill('0') << ltm->tm_min
				<< std::setw(2) << std::setfill('0') << ltm->tm_sec
				<< "] ";
}

//	Status of all accounts
void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

//Status of a single account
void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout 	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

//	Desposits
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";deposit:" << deposit;

	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits ++;
	_totalNbDeposits ++;

	std::cout 	<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

//	Withdrawls
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout 	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount;

	if (_amount >= withdrawal)
	{
		std::cout << ";withdrawal:" << withdrawal;

		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals ++;
		_totalNbWithdrawals ++;

		std::cout 	<< ";amount:" << _amount
					<< ";nb_withdrawals:" << _nbWithdrawals
					<< std::endl;
		return (true);
	}
	else
	{
		std::cout << ";withdrawl:refused" << std::endl;
		return (false);
	}
}
