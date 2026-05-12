/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:22:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/08 14:03:35 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Serializer.hpp"

int main()
{
	uintptr_t addr;
	Data *original = NULL;
	Data *serialized = new Data;
	// original->val = 6;
	serialized->val = 8;
	// std::cout << "original val: " << original->val << std::endl;
	std::cout << "serialized val: " << serialized->val << std::endl;
	addr = Serializer::serialize(original);
	std::cout << "address of original struct: " << original << std::endl;
	std::cout << "address of uintptr: " << addr << std::endl;
	delete serialized;
	serialized = Serializer::deserialize(addr);
	std::cout << "address of serialized struct: " << serialized << std::endl;
	std::cout << "address of uintptr: " << addr << std::endl;

	// std::cout << "original val: " << original->val << std::endl;
	// std::cout << "serialized val: " << serialized->val << std::endl;
	delete original;

	{
		std::cout << "teste 2" << std::endl;
		Data *original = new Data;
		Data *serialized = NULL;
		uintptr_t	addr;
		std::cout << "address of original: " << original << std::endl;
		std::cout << "address of serialized: " << serialized << std::endl;
		addr = Serializer::serialize(original);
		serialized = Serializer::deserialize(addr);
		std::cout << "address of serialized: " << serialized << std::endl;
		delete original;
	}
}