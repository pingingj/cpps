/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:22:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/19 18:32:26 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"


// int main()
// {
// 	Span sp(30);
// 	try
// 	{
// 		sp.addMoreNums(1, 10);
// 		sp.addNumber(999);
// 		// sp.addMoreNums(1, 0);
// 		sp.addMoreNums(-5, 10);
// 		std::cout << "shortest span " << sp.shortestSpan() << std::endl;
// 		std::cout << "longest span " << sp.longestSpan() << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what();
// 	}
// 	std::cout << std::endl;
// 	std::cout << sp << std::endl;
// }

int main()
{
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