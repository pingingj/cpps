/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:38:04 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/27 16:14:53 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("President", 25, 5)
{
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
	this->target = "Default_Target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("President", 25, 5)
{
	std::cout << "PresidentialPardonForm Constructor called." << std::endl;
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj): AForm(obj)
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
	*this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	std::cout << "PresidentialPardonForm Copy assignment called" << std::endl;
	if (this != &obj)
	{
		this->target = obj.getTarget();
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

int	PresidentialPardonForm::ft_execute() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return (0);
}

std::ostream& operator<<(std::ostream& stream, const PresidentialPardonForm& f)
{
	stream << "Form Name: " << f.getName() << std::endl;
	stream << "Sign grade: " << f.getSignGrade() << std::endl;
	stream << "Execution grade: " << f.getExecGrade() << std::endl;
	stream << "Signed: " << f.getSignForm() << std::endl;
	return (stream);
}