/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:08:37 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/03 16:10:41 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//	Libraries
#include <iostream>
#include <string>
#include "Data.hpp"


//	Class
class	Serializer
{
	private:
		Serializer() = delete;
		Serializer(const Serializer &other) = delete;
		Serializer	&operator=(const Serializer &other) = delete;
		~Serializer() = delete;

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};