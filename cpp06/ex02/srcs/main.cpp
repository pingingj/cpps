/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:22:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/04/24 18:47:16 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Base.hpp"
#include <ctime>

int main()
{
	srand(time(0));
	Base *test;

	test = generate();
	identify(test);
	identify(*test);
	
	delete test;
}