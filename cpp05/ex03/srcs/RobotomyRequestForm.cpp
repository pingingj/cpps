/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:56:53 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/27 16:14:42 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robot", 72, 45)
{
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
	this->target = "Default_Target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robot", 72, 45)
{
	std::cout << "RobotomyRequestForm Constructor called." << std::endl;
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj): AForm(obj)
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
	*this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	std::cout << "RobotomyRequestForm Copy assignment called" << std::endl;
	if (this != &obj)
	{
		this->target = obj.getTarget();
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

int	RobotomyRequestForm::ft_execute() const
{
	int	randnum;
	
	std::cout << "*Drilling noises*" << std::endl;
	randnum = rand() % 2;
	if (randnum == 0)
	{
		std::cout << this->target << " has been robotomized :)" << std::endl;
		return (0);
	}
	else
		std::cout << this->target << " has failed the robotomy :(" << std::endl;
	return(1);
}

std::ostream& operator<<(std::ostream& stream, const RobotomyRequestForm& f)
{
	stream << "Form Name: " << f.getName() << std::endl;
	stream << "Sign grade: " << f.getSignGrade() << std::endl;
	stream << "Execution grade: " << f.getExecGrade() << std::endl;
	stream << "Signed: " << f.getSignForm();
	return (stream);
}