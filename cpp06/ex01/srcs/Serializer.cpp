/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:51:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/08 14:07:18 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Serializer.hpp"

Serializer::Serializer()
{
	
}

Serializer::Serializer(const Serializer &obj)
{
	(void)obj;
}

Serializer &Serializer::operator=(const Serializer &obj)
{
	(void)obj;
	return (*this);
}

Serializer::~Serializer()
{

}

uintptr_t Serializer::serialize(Data *ptr)
{
	// if (ptr == NULL)
	// 	return (reinterpret_cast<uintptr_t>(NULL));
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	// if (raw == 0)
	// 	return (reinterpret_cast<Data *>(NULL));
	return (reinterpret_cast<Data *>(raw));
}