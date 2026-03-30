/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:58:27 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/24 17:34:26 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"

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
	std::cout << "this "  << *temp; 
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
	Bureaucrat *low = create_bureaucrat("Low", 150);
	Bureaucrat *mid = create_bureaucrat("Mid", 75);
	Bureaucrat *high = create_bureaucrat("High", 1);
	*high = *low;
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << *low;
	change_grade(low, &Bureaucrat::decrement);
	std::cout << *low << std::endl;
	
	std::cout << *high;
	change_grade(high, &Bureaucrat::increment);
	std::cout << *high << std::endl;

	std::cout << *mid;
	change_grade(mid, &Bureaucrat::increment);
	change_grade(mid, &Bureaucrat::increment);
	change_grade(mid, &Bureaucrat::increment);
	change_grade(mid, &Bureaucrat::increment);
	std::cout << *mid << std::endl;
	
	change_grade(mid, &Bureaucrat::decrement);
	change_grade(mid, &Bureaucrat::decrement);
	change_grade(mid, &Bureaucrat::decrement);
	change_grade(mid, &Bureaucrat::decrement);
	std::cout << *mid << std::endl;
	
	Bureaucrat *fail = create_bureaucrat("Failure", 0);
	(void)fail;
	std::cout << "-----------------------------------------------------" << std::endl;
	delete mid;
	delete high;
	delete low;
}
