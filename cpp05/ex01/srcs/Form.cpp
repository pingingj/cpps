/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:07:48 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/27 17:21:16 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Form.hpp"

Form::Form(): name("Default_Form"), sign_grade(150), exec_grade(150)
{
	std::cout << "Form Default constructor called" << std::endl;
	this->sign_form = false;
}

Form::Form(const std::string name, int sign_grade, int exec_grade): name(name), sign_grade(sign_grade), exec_grade(exec_grade)
{
	std::cout << "Form Constructor called" << std::endl;
	this->sign_form = false;
	if (this->sign_grade < 1 || this->exec_grade < 1)
		throw Form::GradeTooHighException();
	if (this->sign_grade > 150 || this->exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &obj): name(obj.getName()), sign_grade(obj.getSignGrade()), exec_grade(obj.getExecGrade())
{
	std::cout << "Form Copy constructor called" << std::endl;
	*this = obj;
}

Form &Form::operator=(const Form &obj)
{
	std::cout << "Form Copy assignment called" << std::endl;
	if (this != &obj)
	{
		this->sign_form = obj.getSignForm();
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

const std::string Form::getName() const
{
	return (this->name);
}

bool Form::getSignForm() const
{
	return (this->sign_form);
}

int Form::getSignGrade() const
{
	return (this->sign_grade);
}

int Form::getExecGrade() const
{
	return (this->exec_grade);
}


//bad throw i dont like >:(
void	Form::beSigned(Bureaucrat &b)
{
	if (this->sign_form == true)
		throw Form::AlreadySignedException();
	if (b.getGrade() <= this->getSignGrade())
	{
		this->sign_form = true;
	}
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low!");
}

const char *Form::AlreadySignedException::what() const throw()
{
	return ("Form is already signed!");
}


std::ostream& operator<<(std::ostream& stream, const Form& f)
{
	stream << "Form Name: " << f.getName() << std::endl;
	stream << "Sign grade: " << f.getSignGrade() << std::endl;
	stream << "Execution grade: " << f.getExecGrade() << std::endl;
	stream << "Signed: " << f.getSignForm() << std::endl;
	return (stream);
}