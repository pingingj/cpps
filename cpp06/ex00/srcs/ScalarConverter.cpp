/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:19:42 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/04/15 18:41:33 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	(void)obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{

}



void ScalarConverter::converter(std::string str)
{
	double val;
	val = std::strtod(str.c_str(), NULL);
	char c = static_cast<char>(val);
	std::cout << "char: ";
	if (std::isprint(c) && val <= 127 && val >= 0)
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	int num = static_cast<int>(val);
	std::cout << "int: ";
	if (val >= -std::numeric_limits<int>::max() && val <= std::numeric_limits<int>::max())
		std::cout << num << std::endl;
	else
		std::cout << "impossible" << std::endl;
	float fnum = static_cast<float>(val);
	std::cout << "float limits " << -std::numeric_limits<float>::max() << " max " << std::numeric_limits<float>::max() << std::endl;
	std::cout << "float: ";
	if (val >= -std::numeric_limits<float>::max() && val <= std::numeric_limits<float>::max())
		std::cout << fnum << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "double limits " << -std::numeric_limits<double>::max() << " max " << std::numeric_limits<double>::max() << std::endl;	
	std::cout << "double: ";
	if (val >= -std::numeric_limits<double>::max() && val <= std::numeric_limits<double>::max())
		std::cout << val << std::endl;
	else
		std::cout << "impossible" << std::endl;
}