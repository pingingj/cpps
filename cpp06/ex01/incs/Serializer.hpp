/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:41:45 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/04/24 16:05:52 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
	int val;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &obj);
		Serializer &operator=(const Serializer &obj);
		~Serializer();
	public:
		static uintptr_t serialize(Data *ptr);
		static Data	*deserialize(uintptr_t raw);
		
};

#endif