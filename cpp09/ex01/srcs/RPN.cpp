/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:39:54 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/06/11 15:40:14 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RPN.hpp"

bool	parse(std::string &token, std::stack<int> &stack)
{
	// std::cout << "current token: " << token << std::endl;
	if (token.size() != 1)
	{
		std::cerr << "Error: each value must be 1 character" << std::endl;
		return (false);
	}
	if (token.find_first_not_of("1234567890-+*/") != token.npos)
	{
		std::cerr << "Error: Invalid number or operator found" << std::endl;
		return (false);
	}
	if (token.find_first_not_of("-+*/") == token.npos && stack.size() <= 1)
	{
		std::cerr << "Error: Needs more values for operation" << std::endl;
		return (false);
	}
	return (true);
}

bool		calculate(std::string &token, std::stack<int> &stack)
{
	int	x, y;
	x = stack.top();
	stack.pop();
	y = stack.top();
	stack.pop();
	// std::cout << y << " " << token << " " << x << std::endl;
	switch (token[0])
	{
		case '+':
			stack.push(y + x);
			break;
		case '-':
			stack.push(y - x);
			break;
		case '/':
			if (x == 0 || y == 0)
			{
				std::cerr << "Error: Division by 0";
				return (false);
			}
			stack.push(y / x);
			break;
		case '*':
			stack.push(y * x);
	}
	return (true);
}

bool	rpn(std::istringstream &split, std::stack<int> &stack)
{
	std::string token;
	while (split >> token)
	{
		if (parse(token, stack) == false)
			return (false);
		if (isdigit(token[0]))
			stack.push(token[0] - '0');
		else
			if (calculate(token, stack) == false)
				return (false);
	}
	if (token.empty())
	{
		std::cerr << "Error: Empty\n";
		return (false);
	}
	if (token.find_first_not_of("-+*/") != token.npos)
	{
		std::cerr << "Error: Last token must be an operator" << std::endl;
		return (false);
	}
	return (true);
}
