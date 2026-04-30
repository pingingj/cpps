/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:19:42 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/04/30 14:07:45 by dgarcez-         ###   ########.fr       */
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

e_type parse(std::string str)
{
	double val;
	char *flag;
	
	if (str.length() == 0)
		return (INVALID);
	if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan")
		return (SPECIAL);
	if (str.length() == 1 && std::isalpha(str[0]))
		return (CHAR);
	else if(str.find(".") != std::string::npos)
	{
		std::cout << "might be float or double " << std::endl;
		if(str.find_first_not_of("1234567890.-f") != str.npos || std::count(str.begin(), str.end(), '-') > 1 ||  std::count(str.begin(), str.end(), '.') > 1||  std::count(str.begin(), str.end(), 'f') > 1)
			return(INVALID);
		if(str.find('f') != std::string::npos && str[str.find('f') + 1] != '\0')
			return (INVALID);
		if(str[str.find(".") + 1] == '\0' || str[str.find(".") + 1] == 'f')
			return(INVALID);
		if(str.find('-') != std::string::npos && str.find('-') != 0)
			return(INVALID);
		if(str.find('f') != std::string::npos)
			return(FLOAT);
		else
			return(DOUBLE);
	}
	else
	{
		std::cout << "might be int" << std::endl;
		val = std::strtod(str.c_str(),&flag);
		if(*flag == 'f' && *(flag + 1) == '\0')
			return (FLOAT);
		else if (*flag != '\0')
			return (INVALID);
		if (val < -std::numeric_limits<int>::max() || val > std::numeric_limits<int>::max())
			return (DOUBLE);
		return(INT);
	}
	return (INVALID);
}

void	char_converter(char val)
{
	std::cout << "identified as char" << std::endl;
	if (std::isprint(val))
		std::cout << "char: '" << val << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(val) << std::endl;
	std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(val) << std::endl;
}

void	int_converter(int val)
{
	std::cout << "identified as int" << std::endl;
	if (val >= 0 && val <= 127 && std::isprint(static_cast<int>(val)))
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << val << std::endl;
	std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(val) << std::endl;
}

void	float_converter(float val)
{
	std::cout << "identified as float" << std::endl;
	if (val >= 0 && val <= 127 && std::isprint(static_cast<int>(val)))
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (std::isnan(val) || val < -std::numeric_limits<int>::max() || val > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;
	std::cout << "float: " << val << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(val) << std::endl;
}

void	double_converter(double val)
{
	std::cout << "identified as double" << std::endl;
	if (val >= 0 && val <= 127 && std::isprint(static_cast<int>(val)))
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (val < -std::numeric_limits<int>::max() || val > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;
	std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
	std::cout << "double: " << val << std::endl;
}

void	special_converter(double val)
{
	std::cout << "identified as special" << std::endl;
	std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << val << "f" << std::endl;
	std::cout << "double: " << val << std::endl;
}

void ScalarConverter::converter(std::string str)
{
	e_type res;

	res = parse(str);
	std::cout << std::fixed << std::setprecision(2);
	if (res == INVALID)
	{
		std::cout << "identified as impossible" << std::endl;
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else if (res == CHAR)
		char_converter(str[0]);
	else if (res == INT)
		int_converter(std::strtol(str.c_str(), NULL, 10));
	else if (res == FLOAT)
		float_converter(std::strtof(str.c_str(), NULL));
	else if (res == DOUBLE)
		double_converter(std::strtod(str.c_str(), NULL));
	else if (res == SPECIAL)
		special_converter(std::strtod(str.c_str(), NULL));

}