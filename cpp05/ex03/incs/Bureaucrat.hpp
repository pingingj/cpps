/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:19:07 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/30 14:38:00 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int	grade;
	public:
		//constructors
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		~Bureaucrat();

		//member funcs
		void	increment();
		void	decrement();
		void	signForm(AForm &f);
		void	executeForm(AForm const & form) const;

		//getters
		const std::string	getName() const;
		int					getGrade() const;

		//exception classes
		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b);

#endif
