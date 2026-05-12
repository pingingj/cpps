/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:22:55 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/08 18:20:30 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &x, T &y)
{
	std::cout << "SWAP!" << std::endl;
	T temp;

	temp = x;
	x = y;
	y = temp;
}

template <typename T>
T min(T &x, T &y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

template <typename T>
T max(T &x, T &y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

#endif