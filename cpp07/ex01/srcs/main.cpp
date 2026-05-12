/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:22:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/12 16:09:44 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/iter.hpp"


int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	const int arr2[] = {1, 2, 3, 4, 5};
	std::string sarr[] = {"hello", "world", "test"};

	std::cout << "Printing original array without const param" << std::endl;
	iter(arr, 5, print);
	
	std::cout << std::endl;
	std::cout << "Printing const array without const param" << std::endl;
	iter(arr2, 5, print);
	
	std::cout << std::endl;
	std::cout << "Printing original array with const param" << std::endl;
	iter(arr, 5, printInt);
	
	std::cout << std::endl;
	std::cout << "Printing const array with const param" << std::endl;
	iter(arr2, 5, printInt);
	
	std::cout << std::endl;
	std::cout << "Incrementing array" << std::endl;
	iter(arr, 5, incrementInt);
	std::cout << "After increment" << std::endl;
	iter(arr, 5, print);

	std::cout << std::endl;
	std::cout << "String array" << std::endl;
	iter(sarr, 3, printString);
	std::cout << "String array" << std::endl;
	iter(sarr, 3, print);

	// std::cout << "Printing with const template, a non const array" << std::endl;
	// iter(sarr, 3, printconst);
	// std::cout << "Printing with const template, a const array" << std::endl;
	// iter(arr2, 5, printconst);
	return 0;
}