/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:32:42 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/12 16:09:51 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename C> 
void iter(T *array, const int length, void (*func)(C &element))
{
	std::cout << "different types of template" << std::endl;
	for (int i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void iter(T *array, const int length, void (*func)(T &element))
{
	std::cout  << "same type template" << std::endl;
	for (int i = 0; i < length; i++)
	func(array[i]);
}

template <typename T>
void print(T &element)
{
	std::cout << element << std::endl;
}

// template <typename C>
// void printconst(const C &element)
// {
// 	std::cout << element << std::endl;
// }

void printInt(int const& n) {
	std::cout << n << std::endl;
}

void incrementInt(int& n) {
	n += 5;
}

void printString(std::string const& s) {
	std::cout << s << std::endl;
}

#endif