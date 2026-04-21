/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:19:32 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/04/21 18:36:35 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <limits> // for max min
#include <cmath> // for isnan isinf
#include <algorithm> // for isdigit
#include <cctype> // for isprint

enum	e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NaN,
	INF,
	INVALID
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter &operator=(const ScalarConverter &obj);
		~ScalarConverter();
	public:
		static void converter(std::string str);
};

#endif