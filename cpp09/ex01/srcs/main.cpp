/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:22:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/06/11 15:40:19 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RPN.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Invalid amount of arguments. example: ./RPN \"5 9 * 3 - \"" << std::endl;
		return (1);
	}
	std::stack<int> stack;
	std::string input = argv[1];
	std::istringstream split(input);
	if (rpn(split, stack) == false)
		return (1);
	if (stack.size() > 1)
		std::cerr << "Error: Needed more operators" << std::endl;
	else
		std::cout << stack.top() << std::endl;
}