/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:56:22 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/03/27 16:14:23 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrub", 145, 137)
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
	this->target = "Default_Target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrub", 145, 137)
{
	std::cout << "ShrubberyCreationForm Constructor called." << std::endl;
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): AForm (obj)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
	*this = obj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	std::cout << "ShrubberyCreationForm Copy assignment called" << std::endl;
	if (this != &obj)
	{
		this->target = obj.getTarget();
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

int ShrubberyCreationForm::ft_execute() const
{
	std::string		name = this->target + "_shrubbery";
	std::ofstream	file(name.c_str());
	if (file.is_open() == false)
	{
		std::cerr << "Error opening file" << std::endl;
		return (1);
	}
	file << "                                                        .   " << std::endl;
    file << "                                         .         ;        " << std::endl;
    file << "            .              .              ;%     ;;         " << std::endl;
    file << "              ,           ,                :;%  %;          " << std::endl;
    file << "               :         ;                   :;%;'     .,   " << std::endl;
    file << "      ,.        %;     %;            ;        %;'    ,;     " << std::endl;
    file << "        ;       ;%;  %%;        ,     %;    ;%;    ,%'      " << std::endl;
    file << "         %;       %;%;      ,  ;       %;  ;%;   ,%;'       " << std::endl;
    file << "          ;%;      %;        ;%;        % ;%;  ,%;'         " << std::endl;
    file << "           `%;.     ;%;     %;'         `;%%;.%;'           " << std::endl;
    file << "            `:;%.    ;%%. %@;        %; ;@%;%'              " << std::endl;
    file << "               `:%;.  :;bd%;          %;@%;'                " << std::endl;
    file << "                 `@%:.  :;%.         ;@@%;'                 " << std::endl;
    file << "                   `@%.  `;@%.      ;@@%;                   " << std::endl;
    file << "                     `@%%. `@%%    ;@@%;                    " << std::endl;
    file << "                       ;@%. :@%%  %@@%;                     " << std::endl;
    file << "                         %@bd%%%bd%%:;                      " << std::endl;
    file << "                           #@%%%%%:;;                       " << std::endl;
    file << "                           %@@%%%::;                        " << std::endl;
    file << "                           %@@@%(o);  . '                   " << std::endl;
    file << "                           %@@@o%;:(.,'                     " << std::endl;
    file << "                       `.. %@@@o%::;                        " << std::endl;
    file << "                          `)@@@o%::;                        " << std::endl;
    file << "                           %@@(o)::;                        " << std::endl;
    file << "                          .%@@@@%::;                        " << std::endl;
    file << "                          ;%@@@@%::;.                       " << std::endl;
    file << "                         ;%@@@@%%:;;;.                      " << std::endl;
    file << "                     ...;%@@@@@%%:;;;;,..                   " << std::endl;
	file.close();
	return (0);
}

std::ostream& operator<<(std::ostream& stream, const ShrubberyCreationForm& f)
{
	stream << "Form Name: " << f.getName() << std::endl;
	stream << "Sign grade: " << f.getSignGrade() << std::endl;
	stream << "Execution grade: " << f.getExecGrade() << std::endl;
	stream << "Signed: " << f.getSignForm();
	return (stream);
}