/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:45:30 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/09 15:14:59 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//	Libraries
#include <iostream>
#include <string>

//	Temaplates
template <typename T, typename F>
void	iter(T *arr, int size, F func)
{
	if (arr == NULL || func == NULL)
		return;
	for (int i = 0; i < size; i++)
		func(arr[i]);
}