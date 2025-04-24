/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:29:53 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/24 12:40:58 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Libraries
#include <iostream>
#include <string>
#include <stack>
#include <exception>


//	Class
class	RPN
{
	private:
		std::stack<int>		numbers;

	public:
		RPN();
		RPN(const RPN &other);
		~RPN();

		RPN	&operator=(const RPN &other);

		void	calculate(std::string input);
		bool	isoperator(char c);
		int		do_operation(int a, int b, char o);

		//	Exceptions
		class	EmptyInputException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	InvalidInputException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	DivByZeroException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	UnexpectedException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	InvalidStackState : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};