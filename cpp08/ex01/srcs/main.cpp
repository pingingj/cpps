/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:22:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/29 13:36:48 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"


int main()
{
	{
		std::cout << "my Tests" << std::endl;
		Span sp(30);
		try
		{
			sp.addNumber(634);
			sp.addNumber(2142);
			sp.addNumber(64);
			sp.addNumber(1);
			sp.addNumber(661);
			// sp.addMoreNums(4, 50);
			std::cout << "Span: " << sp << std::endl;
			std::cout << "shortest span " << sp.shortestSpan() << std::endl;
			std::cout << "longest span " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}
		std::cout << std::endl;
		std::cout << "Span: " << sp << std::endl;
		// try
		// {
		// 	sp.addNumber(3);
		// }
		// catch(const std::exception& e)
		// {
		// 	std::cerr << e.what() << '\n';
		// }
		Span copied;
		copied = sp;
		std::cout << "copied: " << copied << std::endl;
	}
	{
		std::cout << "Their main" << std::endl;
		Span sp = Span(6);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		return 0;
	}
}