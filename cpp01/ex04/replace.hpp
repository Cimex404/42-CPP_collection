/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:34:42 by jgraf             #+#    #+#             */
/*   Updated: 2025/02/20 12:16:24 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_H
# define REPLACE_H

//	Libraries
# include <iostream>
# include <string>
# include <fstream>

//	Functions
void	replace_string_in_file(std::string input_file, std::string output_file, std::string s1, std::string s2);

#endif