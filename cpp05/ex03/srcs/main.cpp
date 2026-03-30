/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:58:27 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/30 14:44:09 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Intern.hpp"
#include "../incs/AForm.hpp"
#include "../incs/Bureaucrat.hpp"

int main()
{
	Intern	tester;
	AForm	*form;
	Bureaucrat smart("Daniel", 1);
	
	form = tester.makeForm("robotomy request", "robot");
	smart.executeForm(*form);
	smart.signForm(*form);
	delete form;
	form = tester.makeForm("shrubbery creation", "shrub");
	smart.executeForm(*form);
	smart.signForm(*form);
	delete form;
	form = tester.makeForm("presidential pardon", "Pres");
	smart.executeForm(*form);
	smart.signForm(*form);
	delete form;
}
