/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:52:31 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/30 14:41:56 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
	std::cout << "Intern Copy constructor called" << std::endl;
	*this = obj;
}

Intern &Intern::operator=(const Intern &obj)
{
	std::cout << "Intern Copy assignment operator called" << std::endl;
	if (this != &obj)
		(void)obj;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm	*form;
	int	i = 0;

	while(i < 3 && forms[i] != name)
		i++;

	switch(i)
	{
		case 0:
			form = new PresidentialPardonForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			std::cerr << name << " Form doesn't exist" << std::endl;
			return (NULL);
	}
	std::cout << "Intern creates " << form->getName() << std::endl;
	return (form);
}