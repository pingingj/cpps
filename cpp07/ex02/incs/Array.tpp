/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:26:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/12 16:26:06 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Array.hpp"

template<typename T>
Array<T>::Array()
{
	std::cout << "Default constructor" << std::endl;
	this->n = 0;
	this->array = new T[n];
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Constructor with size" << std::endl;
	this->n = n;
	this->array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		this->array[i] = 0;
}

template<typename T>
Array<T>::Array(const Array<T> &obj)
{
	std::cout << "Copy constructor" << std::endl;
	this->array = NULL;
	*this = obj;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &obj)
{
	std::cout << "Assignment operator overload " << std::endl;
	if (this != &obj)
	{
		delete[] this->array;
		this->array = new T[obj.size()];
		this->n = obj.size();
		for (unsigned int i = 0; i < obj.size(); i++)
			this->array[i] = obj.array[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	std::cout << "Destructor called" << std::endl;
	delete[] this->array;
}

template<typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->size() || this->size() == 0)
		throw std::out_of_range("catch! out of range");
	else
		return (this->array[index]);
}

template<typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	// std::cout << "const [] overload" << std::endl;
	if (index >= this->size() || this->size() == 0)
		throw std::out_of_range("catch const! out of range");
	else
		return (this->array[index]);
}

template<typename T>
unsigned int Array<T>::size() const
{
	return (this->n);
}