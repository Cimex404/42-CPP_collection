/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:12:35 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/30 08:31:30 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <chrono>

//	Class
class	PmergeMe
{
	private:
		std::string	container_type;

	public:
		PmergeMe(std::string name);
		PmergeMe(const PmergeMe &other);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &other);

		//	Algorithm
		template <typename Con>
		void	merge_insert(Con &container);

		template <typename Con>
		Con		generate_jacobsthal(size_t n);

		template <typename Con>
		void	print_content(Con container, std::string prefix);

		template <typename Con>
		void	sort(Con &container, bool print_container);

		//	Exceptions
		class NegativeException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class InvalidInputException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};


//	Generate Jacobsthal numbers (J(n) = J(n-1) + 2J(n-2))
template <typename Con>
Con	PmergeMe::generate_jacobsthal(size_t n)
{
	Con	jacobsthal;
	if (n == 0)
		return (jacobsthal);
	jacobsthal.push_back(0);
	if (n == 1)
		return (jacobsthal);
	jacobsthal.push_back(1);
	for (size_t i = 2; i < n; ++i)
		jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
	return (jacobsthal);
}


//	Ford Johnson algorithm
template <typename Con>
void PmergeMe::merge_insert(Con &container)
{
	if (container.size() <= 1)
		return;

	Con	smaller;
	Con	larger;

	//	Step 1: Pair elements and sort within pairs
	for (size_t i = 0; i < container.size()-1; i += 2)
	{
		if (container[i] > container[i + 1])
		{
			larger.push_back(container[i]);
			smaller.push_back(container[i + 1]);
		}
		else
		{
			smaller.push_back(container[i]);
			larger.push_back(container[i + 1]);
		}
	}

	//	Push remaining element to the "smaller" container
	if (container.size() % 2 != 0)
		smaller.push_back(container.back());

	//	Step 2: Recursively sort larger elements
	merge_insert(larger);

	//	Step 3: Build result from sorted larger elements
	Con	result = larger;

	//	Step 4: Prepare Jacobsthal insertion order for rest
	Con	jacobsthal = generate_jacobsthal<Con>(smaller.size());
	Con	indices;
	for (size_t i = 0; i < smaller.size(); ++i)
		indices.push_back(i);

	Con	insertion_order;
	Con	inserted(indices.size(), false);
	for (size_t i = 1; i < jacobsthal.size() && insertion_order.size() < indices.size(); ++i)
	{
		size_t idx = jacobsthal[i] - 1;
		if (idx < indices.size() && !inserted[idx])
		{
			insertion_order.push_back(indices[idx]);
			inserted[idx] = true;
		}
	}
	
	for (size_t i = 0; i < indices.size(); ++i)
	{
		if (!inserted[i])
			insertion_order.push_back(indices[i]);
	}

	//	Step 5: Insert remaining smaller elements
	for (size_t i = 0; i < insertion_order.size(); ++i)
		result.insert(std::upper_bound(result.begin(), result.end(), smaller[insertion_order[i]]), smaller[insertion_order[i]]);

	//	Step 6: Assign sorted array to original array
	container = result;
}


template <typename Con>
void	PmergeMe::print_content(Con container, std::string prefix)
{
	std::cout << prefix;
	for (size_t i = 0; i < container.size(); i++)
		std::cout << " " << container[i];
	std::cout << std::endl;
}

template <typename Con>
void	PmergeMe::sort(Con &container, bool print_container)
{
	if (print_container)
		print_content<Con>(container, "Before:\t");
	clock_t	start = clock();
	merge_insert(container);
	clock_t	end = clock();
	double	time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
	if (print_container)
		print_content<Con>(container, "After:\t");

	std::cout	<< "Time to process a range of " << container.size()
				<< " elements with " << this->container_type << ":\t"
				<< time << " us" << std::endl;
}