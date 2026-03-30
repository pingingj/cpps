/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:10:39 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/30 14:51:22 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default")
{
	std::cout << "Bureaucrat Default constructor called." << std::endl;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	std::cout << "Bureaucrat Copy constructor called." << std::endl;
	*this = obj;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	std::cout << "Bureaucrat Copy assignment called." << std::endl;
	if (this != &obj)
	{
		this->grade = obj.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called." << std::endl;
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

void	Bureaucrat::increment()
{
	std::cout << "Incrementing " << this->getName() << "'s grade" << std::endl;
	if (this->getGrade() == 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade--;
}

void	Bureaucrat::decrement()
{
	std::cout << "Decrementing " << this->getName() << "'s grade" << std::endl;
	if (this->getGrade() == 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade++;
}

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() <<  " couldn't sign ";
		std::cerr << f.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Bureaucrat "<< this->getName() << "'s " << e.what() << std::endl;
		std::cerr << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is too low!");
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b)
{
	stream << "Name " << b.getName() << ", bureaucrat grade: " << b.getGrade();
	return (stream);
}