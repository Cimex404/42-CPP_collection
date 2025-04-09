/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:37:11 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/08 10:26:22 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Array.hpp"

//	Constructors
template <class T>
Array<T>::Array()
{
	arr = new T[0];
	len = 0;
}

template <class T>
Array<T>::Array(unsigned int n)
{
	this->len = n;
	this->arr = new T[this->len];
}

template <class T>
Array<T>::Array(Array &other)
{
	this->len = other.size();
	this->arr = new T[this->len];

	for (size_t i = 0; i < this->len; i++)
		this->arr[i] = other.arr[i];
}


//	Assignment operator overload
template <class T>
Array<T>	&Array<T>::operator=(Array &other)
{
	if (this->arr != NULL)
		delete [] this->arr;
	if (other.size() > 0)
	{
		this->len = other.size();
		this->arr = new T[this->len];
		for (size_t i = 0; i < this->size(); i++)
			this->arr[i] = other.arr[i];
	}
	return (*this);
}


//	Destructor
template <class T>
Array<T>::~Array()
{
	if (this->arr)
		delete [] this->arr;
}


//	Getters
template <class T>
size_t	Array<T>::size() const
{
	return (this->len);
}


//	Access operator overload
template <class T>
T	&Array<T>::operator[](unsigned int index)
{
	if (!arr || index >= this->len)
		throw Array::InvalidIndexException();
	return (this->arr[index]);
}

//	Exception
template	<typename T>
const char	*Array<T>::InvalidIndexException::what() const throw()
{
	return ("Index out of range!");
}