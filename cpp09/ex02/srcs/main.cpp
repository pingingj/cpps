/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:49:30 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/06/24 21:13:14 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Incorrect amount of arguments. \"./PmergeMe 3 6 1 2 67\"" << std::endl;
		return (1);
	}
	PmergeMe pmo;
	for(int i = 1; argv[i]; i++)
	{
		if (pmo.parse(argv[i]) == false)
			return (1);
	}
	pmo.sort_vector();
	pmo.sort_deque();
}