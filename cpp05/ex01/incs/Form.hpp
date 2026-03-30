/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:54:09 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/19 17:33:04 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool	sign_form;
		const int	sign_grade;
		const int	exec_grade;
	public:
		//constructors
		Form();
		Form(const std::string name, int sign_grade, int exec_grade);
		Form(const Form &obj);
		Form &operator=(const Form &obj);
		~Form();
		
		//getters
		const std::string getName() const;
		bool getSignForm() const;
		int getSignGrade() const;
		int getExecGrade() const;
		
		//member funcs
		void beSigned(Bureaucrat &b);

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

std::ostream& operator<<(std::ostream& stream, const Form& b);

#endif