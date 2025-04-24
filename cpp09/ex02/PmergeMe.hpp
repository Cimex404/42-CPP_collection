/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:12:35 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/24 17:43:31 by jgraf            ###   ########.fr       */
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
class PmergeMe
{
	private:
		std::string	container_type;

    public:
        PmergeMe(std::string name);
        PmergeMe(const PmergeMe &other);
        ~PmergeMe();

        PmergeMe &operator=(const PmergeMe &other);

        //	Algorithm
        std::vector<size_t>	generate_jacobsthal(size_t n);

        template <typename Con>
        void	merge_insert(Con &container);

		template <typename Con>
		void	print_content(Con container, std::string prefix);

        template <typename Con>
        void	sort(Con &container);

        //	Exceptions
        class NegativeException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};


//	Ford Johnson algorithm
template <typename Con>
void	PmergeMe::merge_insert(Con &container)
{
	if (container.size() <= 1)
		return;

	Con	smaller;
	Con	larger;

	// Step 1: Pair elements, sort within pairs
	for (size_t i = 0; i < container.size() - 1; i += 2)
	{
		if (container[i] > container[i + 1])
			std::swap(container[i], container[i + 1]);
		smaller.push_back(container[i]);
		larger.push_back(container[i + 1]);
	}

	// If odd number of elements, last element goes to smaller
	if (container.size() % 2 != 0)
		smaller.push_back(container.back());

	// Step 2: Recursively sort the larger elements
	merge_insert(larger);

	// Step 3: Insert smaller elements into the sorted larger sequence
	Con	result;
	if (!larger.empty())
		result.push_back(larger[0]);

	// Generate Jacobsthal indices for insertion order
	std::vector<size_t>	indices;
	std::vector<size_t> jacobsthal = generate_jacobsthal(smaller.size());
	for (size_t i = 1; i < smaller.size(); ++i)
		indices.push_back(i);

	std::vector<size_t>	insertion_order;
	std::vector<bool>	inserted(indices.size(), false);
	for (size_t i = 1; i < jacobsthal.size() && insertion_order.size() < indices.size(); ++i)
	{
		size_t idx = jacobsthal[i] - 1;
		if (idx < indices.size() && !inserted[idx])
		{
			insertion_order.push_back(indices[idx]);
			inserted[idx] = true;
		}
	}

	// Insert any remaining indices
	for (size_t i = 0; i < indices.size(); ++i)
	{
		if (!inserted[i])
			insertion_order.push_back(indices[i]);
	}

	// Insert smaller[i] into correct position in result
	for (size_t i = 0; i < insertion_order.size(); ++i)
	{
		auto	it = std::upper_bound(result.begin(), result.end(), smaller[insertion_order[i]]);
		result.insert(it, smaller[insertion_order[i]]);
	}

	// Add the first smaller element, which was not included in Jacobsthal loop
	if (!smaller.empty())
	{
		auto	it = std::upper_bound(result.begin(), result.end(), smaller[0]);
		result.insert(it, smaller[0]);
	}

	// Add remaining larger elements that were skipped initially
	for (size_t i = 1; i < larger.size(); ++i)
	{
		auto	it = std::upper_bound(result.begin(), result.end(), larger[i]);
		result.insert(it, larger[i]);
	}

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
void	PmergeMe::sort(Con &container)
{
	print_content<Con>(container, "Before:");
	clock_t	start = clock();
    merge_insert(container);
	clock_t	end = clock();
	double	time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
	print_content<Con>(container, "After:");

    std::cout << "Time to process a range of " << container.size() << " elements with " << this->container_type << ": " << time << " us" << std::endl;
}