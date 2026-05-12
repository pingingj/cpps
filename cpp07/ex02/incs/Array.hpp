/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:13:38 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/08 18:19:28 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T *array;
		unsigned int n; // size
	public:
		//constructors
		Array();
		Array(unsigned int n);
		Array(const Array &obj);
		~Array();
		
		//overloads
		Array &operator=(const Array &obj);
		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;
		
		//funcs
		unsigned int size() const;
};
#include "Array.tpp"

#endif