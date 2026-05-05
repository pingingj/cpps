/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:26:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/04 17:25:07 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Array.hpp"

template<typename T> Array<T>::Array()
{
	std::cout << "Default constructor" << std::endl;
	this->n = 1;
	this->array = new T[n];
}

template<typename T> Array<T>::Array(unsigned int n)
{
	std::cout << "Constructor with size" << std::endl;
	this->n = n;
	this->array = new T[n];
}

template<typename T> Array<T>::Array(const Array<T> &obj)
{
	*this = obj;
}

template<typename T> Array<T> &Array<T>::operator=(const Array<T> &obj)
{
	if (this != &obj)
	{
		if (this->array)
			delete[] array;
		this->array = new T[obj.size()];
		this->n = obj.size();
	}
	return (*this);
}

template<typename T> Array<T>::~Array()
{
	std::cout << "Destructor called" << std::endl;
	delete[] this->array;
}

template<typename T> T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->size())
		throw std::out_of_range("out of range detected...");
	else
		return (this->array[index]);
}

template<typename T> unsigned int Array<T>::size()
{
	return (this->n);
}