/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:36:49 by jgraf             #+#    #+#             */
/*   Updated: 2025/04/02 14:41:37 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//	Constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), target("Default")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("Default", 72, 45), target(other.getTarget())
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		this->target = other.getTarget();
	return (*this);
}


//	Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	
}


//	Getter
std::string	RobotomyRequestForm::getTarget() const
{
	return (this->target);
}


//	Execute
void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	static int	success = 0;

	if (!getSigned())
		throw AForm::NotSignedException();
	else if (executor.getGrade() > getExeGrade())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "BRRRRRT BRR BRRRRRRRRRRTTTT!!!\t";
		if (!(success % 2))
			std::cout << "The robotimazion of " << target << " was successfull!" << std::endl;
		else
			std::cout << "The robotimazion failed!" << std::endl;
		success ++;
	}
}