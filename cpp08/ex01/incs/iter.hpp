/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:32:42 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/04 16:04:54 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void iter(T *array, const int length, void (*func)(T element))
{
	for (int i = 0; i < length; i++)
		func(array[i]);
}

template <typename T> void print(T element)
{
	std::cout << element;
}
#endif