/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:58:27 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/26 17:46:32 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"

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

Form	*create_form(const std::string name, const int sign_grade, const int exec_grade)
{
	std::cout << "Creating " << name << " form with sign grade " << sign_grade;
	std::cout << " and execution grade " << exec_grade << std::endl;
	Form *temp;
	try
	{
		temp = new Form(name, sign_grade, exec_grade);
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

int main()
{
	Bureaucrat	*low = create_bureaucrat("Low", 160);
	Bureaucrat	*mid = create_bureaucrat("Mid", 160);
	Bureaucrat	*high = create_bureaucrat("High", 1);
	Form		*contract = create_form("important spiel", 72, 70);
	Form		*economy = create_form("economy", 1, 1);

	std::cout << "-----------------------------------------------------" << std::endl;

	std::cout << *mid;
	std::cout << *contract;
	mid->signForm(*contract);
	std::cout << std::endl;
	
	change_grade(mid, &Bureaucrat::decrement);
	change_grade(mid, &Bureaucrat::decrement);
	change_grade(mid, &Bureaucrat::decrement);
	change_grade(mid, &Bureaucrat::decrement);
	
	std::cout << std::endl;
	std::cout << *mid;
	std::cout << *contract;
	mid->signForm(*contract);
	std::cout << std::endl;
	std::cout << *mid;
	std::cout << *economy;
	mid->signForm(*economy);
	Bureaucrat *fail = create_bureaucrat("Failure", 0);
	Form *mega_fail = create_form("Failure", 1, 0);
	(void)fail;
	(void)mega_fail;

	std::cout << "-----------------------------------------------------" << std::endl;

	delete mid;
	delete high;
	delete low;
	delete contract;
	delete economy;
}
