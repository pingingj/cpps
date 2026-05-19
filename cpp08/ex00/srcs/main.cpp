/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:22:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/19 17:25:47 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/easyfind.hpp"
#include <list>
#include <vector>


int main( void ) 
{
	std::vector<int> v;
	std::list<int> l;

	for(unsigned int i = 0;i < 5;i++)
		v.push_back(i);
	
	for(unsigned int i = 0;i <= 5;i++)
		l.push_back(i);

	std::vector<int>::iterator it = easyfind(v,3);
	std::cout << "searching through vector " << 3 << std::endl;
	if (it != v.end())
		std::cout << "found: (" << *it << ") in the container\n";
	else
		std::cout << "didn't find anything" << std::endl;
	std::cout << "searching through list " << 5 << std::endl;
	std::list<int>::iterator it2 = easyfind(l,5);
	if (it2 != l.end())
		std::cout << "found: (" << *it2 << ") in the container\n";
	else
		std::cout << "didn't find anything" << std::endl;
	return 0;
}