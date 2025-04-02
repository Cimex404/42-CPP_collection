/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:36:49 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/02 14:38:44 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//	Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), target("Default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creatoin Form", 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("Default", 145, 137), target(other.getTarget())
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->target = other.getTarget();
	return (*this);
}


//	Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}


//	Getter
std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}


//	Execute
void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!getSigned())
		throw AForm::NotSignedException();
	else if (executor.getGrade() > getExeGrade())
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream out((target + std::string("_shrubbery")).c_str());

		if (out)
		{
			out << executor.getName() << " executed " << target << " and this is the result:\n" << std::endl;
			out << "        *			" << std::endl;
			out << "       * *			" << std::endl;
			out << "      *   *			" << std::endl;
			out << "     *     *		" << std::endl;
			out << "    *       *		" << std::endl;
			out << "   *         *		" << std::endl;
			out << "  *           *		" << std::endl;
			out << " *             *	" << std::endl;
			out << "*****************	" << std::endl;
			out << "       |||			" << std::endl;
			out << "       |||			" << std::endl;
			out.close();
			std::cout << executor.getName() << " executed " << target << std::endl;
		}
		else
			throw ShrubberyCreationForm::OpenFileExeption();
	}
}


//	Exception
const char	*ShrubberyCreationForm::OpenFileExeption::what() const throw()
{
	return ("Failed to open file!");
}