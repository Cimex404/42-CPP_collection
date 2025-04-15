/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:29:03 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/15 13:41:54 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"

int	main()
{
	std::cout << "\n\tTesting with int\n" << std::endl;
	MutantStack<int> intStack;
	intStack.push(42);
	intStack.push(-1);
	intStack.push(2024);
	intStack.push(0);

	std::cout << "Iterating using non-const iterator:" << std::endl;
	for (MutantStack<int>::iterator it = intStack.begin(); it != intStack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "Iterating using const_iterator:" << std::endl;
	for (MutantStack<int>::const_iterator cit = intStack.begin(); cit != intStack.end(); ++cit)
		std::cout << *cit << std::endl;

	std::cout << "\n\tTesting with std::string\n" << std::endl;
	MutantStack<std::string> stringStack;
	stringStack.push("Check out");
	stringStack.push("How my");
	stringStack.push("MutantStack");
	stringStack.push("is");
	stringStack.push("awesome!");

	std::cout << "All elements:" << std::endl;
	for (MutantStack<std::string>::const_iterator it = stringStack.begin(); it != stringStack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Top element: " << stringStack.top() << std::endl;
	stringStack.pop();
	std::cout << "Top after pop: " << stringStack.top() << std::endl;
	std::cout << std::endl;

	std::cout << "\n\tTesting with float\n" << std::endl;
	MutantStack<float> floatStack;
	floatStack.push(3.14f);
	floatStack.push(1.618f);
	floatStack.push(2.718f);
	floatStack.push(1.414f);

	std::cout << "All elements:" << std::endl;
	for (MutantStack<float>::iterator it = floatStack.begin(); it != floatStack.end(); ++it)
		std::cout << (*it) << std::endl;
	std::cout << "\nIterating backwards:" << std::endl;
	MutantStack<float>::iterator ite = floatStack.end();
	MutantStack<float>::iterator itb = floatStack.begin();
	while (ite != itb) 
	{
		--ite;
		std::cout << *ite << std::endl;
	}

	std::cout << "\n\tTesting edge case with empty MutantStack<int>" << std::endl;
	MutantStack<int> emptyStack;
	std::cout << "Is stack empty? " << (emptyStack.empty() ? "Yes" : "No") << std::endl;
	if (!emptyStack.empty())
		std::cout << "Unexpected non-empty stack!" << std::endl;

	std::cout << "\n\tTesting copy and assignment (on Stack<int>)" << std::endl;
	MutantStack<int> copiedStack = intStack;
	MutantStack<int> assignedStack;
	assignedStack = intStack;

	std::cout << "Copied stack size: " << copiedStack.size() << std::endl;
	std::cout << "Assigned stack size: " << assignedStack.size() << std::endl;
}