/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:58:27 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/30 15:31:59 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/PresidentialPardonForm.hpp"
#include "../incs/AForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include <ctime>   // Needed for time
#include <unistd.h>


Bureaucrat	*create_bureaucrat(const std::string name, int grade)
{
	std::cout << "Creating " << name << " bureaucrat with grade " << grade << std::endl;
	Bureaucrat *temp;
	try
	{
		temp = new Bureaucrat(name, grade);
	}
	catch (std::exception &e)
	{
		std::cerr << name << " " << e.what() << std::endl;
		return (NULL);
	}
	std::cout << "giga success" << std::endl;	 
	return (temp);
}

AForm	*create_form(const std::string name, char which)
{
	std::cout << "Creating " << name << " form" << std::endl;
	AForm *temp;
	try
	{
		if (which == 'P')
			temp = new PresidentialPardonForm(name);
		else if (which == 'R')
			temp = new RobotomyRequestForm(name);
		else if (which == 'S')
			temp = new ShrubberyCreationForm(name);
		else
			return (NULL);
	}
	catch (std::exception &e)
	{
		std::cerr << name << " " << e.what() << std::endl;
		return (NULL);
	}
	std::cout << "giga success" << std::endl;	 
	return (temp);
}

bool	change_grade(Bureaucrat *b, void (Bureaucrat::*function)())
{
	try
	{
		(b->*function)();
	}
	catch (std::exception &e)
	{
		std::cerr << b->getName() << " " << e.what() << std::endl;
		return (false);
	}
	std::cout << "Grade changed" << std::endl;
	return (true);
}

void	execute_forms(Bureaucrat *bures[3], AForm *form)
{
	int	i = 0;
	while(i < 3)
	{
		bures[i]->executeForm(*form);
		i++;
	}
}

void	delete_vars(Bureaucrat **bures, AForm **forms)
{
	int	i = 2;

	while(i >= 0)
	{
		if (bures[i])
			delete bures[i];
		if (forms[i])
			delete forms[i];
		i--;
	}
}

int main()
{
	srand(time(0));
	Bureaucrat	*bures[3];
	AForm		*forms[3];
	bures[0] = create_bureaucrat("Low", 120);
	bures[1] = create_bureaucrat("Mid", 30);
	bures[2] = create_bureaucrat("High", 1);
	forms[0] = create_form("Shrub", 'S');
	forms[1] = create_form("Robot", 'R');
	forms[2] = create_form("President", 'P');
	for(int j = 0; j < 3; j++)
	{
		if (bures[j] == NULL || forms[j] == NULL)
		{
			delete_vars(bures, forms);
			return (1);
		}
	}
	std::cout << "-----------------------------------------------------" << std::endl;

	execute_forms(bures, forms[0]);
	execute_forms(bures, forms[1]);
	execute_forms(bures, forms[2]);
	
	bures[1]->signForm(*forms[0]);
	std::cout << std::endl;
	
	std::cout << *bures[1] << std::endl;
	std::cout << *forms[0] << std::endl;

	bures[1]->signForm(*forms[0]);
	std::cout << std::endl;

	std::cout << *bures[1] << std::endl;
	std::cout << *forms[1] << std::endl;

	bures[1]->signForm(*forms[1]);
	Bureaucrat *fail = create_bureaucrat("Failure", 0);
	// AForm *mega_fail = create_form("Failure", 1, 0);
	(void)fail;
	// (void)mega_fail;
	std::cout << "-----------------------------------------------------" << std::endl;
	delete_vars(bures, forms);
}
