/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:27:52 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/14 09:19:26 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//	Libraries
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <list>

//	Class
template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		~MutantStack();
		MutantStack	&operator=(const MutantStack &other);

		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator				begin();
		iterator				end();
		const_iterator			begin() const;
		const_iterator			end() const;
		reverse_iterator		rbegin();
		reverse_iterator		rend();
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};