/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:07:48 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/19 17:33:42 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/AForm.hpp"

AForm::AForm(): name("Default_AForm"), sign_grade(150), exec_grade(150)
{
	std::cout << "AForm Default constructor called" << std::endl;
	this->sign_form = false;
}

AForm::AForm(const std::string name, int sign_grade, int exec_grade): name(name), sign_grade(sign_grade), exec_grade(exec_grade)
{
	std::cout << "AForm Constructor called" << std::endl;
	this->sign_form = false;
	if (this->sign_grade < 1 || this->exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (this->sign_grade > 150 || this->exec_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &obj): name(obj.getName()), sign_grade(obj.getSignGrade()), exec_grade(obj.getExecGrade())
{
	std::cout << "AForm Copy constructor called" << std::endl;
	*this = obj;
}

AForm &AForm::operator=(const AForm &obj)
{
	std::cout << "AForm Copy assignment called" << std::endl;
	if (this != &obj)
	{
		this->sign_form = obj.getSignForm();
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

const std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getSignForm() const
{
	return (this->sign_form);
}

int AForm::getSignGrade() const
{
	return (this->sign_grade);
}

int AForm::getExecGrade() const
{
	return (this->exec_grade);
}

std::string AForm::getTarget() const
{
	return (this->target);
}

void	AForm::beSigned(Bureaucrat const &b)
{
	if (this->sign_form == true)
		throw AForm::AlreadySignedException();
	if (b.getGrade() <= this->getSignGrade())
	{
		this->sign_form = true;
	}
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
	int	result;
	if (this->sign_form == true)
		throw AForm::AlreadySignedException();
	if (executor.getGrade() <= this->getSignGrade() && executor.getGrade() <= this->getExecGrade())
	{
		result = this->ft_execute();
		if (result == 0)
		{
			std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		}
		else
			std::cout << executor.getName() << " execution failed!" << std::endl;
	}
	else
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low!");
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return ("is already signed!");
}


std::ostream& operator<<(std::ostream& stream, const AForm& f)
{
	stream << "Form Name: " << f.getName() << std::endl;
	stream << "Sign grade: " << f.getSignGrade() << std::endl;
	stream << "Execution grade: " << f.getExecGrade() << std::endl;
	stream << "Signed: " << f.getSignForm() << std::endl;
	return (stream);
}