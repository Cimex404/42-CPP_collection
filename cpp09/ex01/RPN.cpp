/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:29:32 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/24 12:41:21 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//	Constructors
RPN::RPN()
{

}

RPN::RPN(const RPN &other)
{
	numbers = other.numbers;
}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other)
		numbers = other.numbers;
	return (*this);
}


//	Destructor
RPN::~RPN()
{
	
}


//	Calculate
bool	RPN::isoperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

int		RPN::do_operation(int a, int b, char o)
{
	switch(o)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
				throw DivByZeroException();
			return (a / b);
		default:
			throw UnexpectedException();
	}
}

void	RPN::calculate(std::string input)
{
	if (input.empty())
		throw EmptyInputException();
	for (size_t i = 0; i < input.length(); i++)
	{
		if (std::isdigit(input[i]))
			numbers.push(input[i] - '0');
		else if (isoperator(input[i]))
		{
			if (numbers.size() < 2)
				throw InvalidStackState();
			int topped = numbers.top();
			numbers.pop();
			numbers.top() = do_operation(numbers.top(), topped, input[i]);
		}
		else if (input[i] == ' ')
			continue;
		else
			throw InvalidInputException();
	}
	if (numbers.size() != 1)
		throw InvalidStackState();
	std::cout << numbers.top() << std::endl;
}


//	Exceptions
const char	*RPN::EmptyInputException::what() const throw()
{
	return ("Input can't be empty!");
}

const char	*RPN::InvalidInputException::what() const throw()
{
	return ("Input contains invalid characters!");
}

const char	*RPN::DivByZeroException::what() const throw()
{
	return ("A division by 0 is not possible!");
}

const char	*RPN::UnexpectedException::what() const throw()
{
	return ("Even the program has problems understanding this error!");
}

const char	*RPN::InvalidStackState::what() const throw()
{
	return ("There is an invalid number of elements in the stack for this operation!");
}