/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:54:09 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/30 14:38:46 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
	protected:
		std::string target;
		virtual int ft_execute() const = 0;

	private:
		const std::string	name;
		bool				sign_form;
		const int			sign_grade;
		const int			exec_grade;

	public:
		//constructors
		AForm();
		AForm(const std::string name, int sign_grade, int exec_grade);
		AForm(const AForm &obj);
		AForm &operator=(const AForm &obj);
		virtual ~AForm();
		
		//getters
		const std::string	getName() const;
		bool 				getSignForm() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		std::string			getTarget() const;
		
		//member funcs
		void beSigned(Bureaucrat const &b);
		void execute(Bureaucrat const & executor) const;

		//exception classes
		class GradeTooHighException: public std::exception
		{
			virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			virtual const char *what() const throw();
		};

		class AlreadySignedException: public std::exception
		{
			virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& stream, const AForm& f);

#endif