/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:22:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/12 16:29:05 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Array.hpp"
#include <ctime>
#include <cstdlib>
#define MAX_VAL 10

int main()
{
	//their main
	{
		std::cout << "THEIR MAIN (with some changes)" << std::endl << std::endl;
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			std::cout << "out of bounds -2" << std::endl;
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "testing max value" << std::endl;
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "printing array" << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << "i = " << i << " value :" << numbers[i] << std::endl;
		}
		delete [] mirror;//
	}
	
	//my main
	std::cout << std::endl << "MY MAIN" << std::endl << std::endl;
	try
	{
		std::cout << "Array of ints" << std::endl;
		Array<int> ar;
		ar[0] = 42;
		Array<int> ar2(ar);
		Array<int> ar3(3);
		ar3[0] = 42;
		ar3[1] = 60;
		ar3[2] = 120;
		ar = ar3;
		std::cout << "ar[0] = " << ar[0] << std::endl;
		std::cout << "ar size = " << ar.size() << std::endl;
		std::cout << "ar2 size = " << ar2.size() << std::endl;
		std::cout << "ar3 size = " << ar3.size() << std::endl;
		std::cout << "ar3[0] = " << ar3[0] << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Const array of floats" << std::endl;
		const Array<float> ar(5);
		Array<float> ar2(ar);
		Array<float> ar3 = ar;
		std::cout << "ar[0] = " << ar[0] << std::endl;
		std::cout << "ar size = " << ar.size() << std::endl;
		std::cout << "ar2 size = " << ar2.size() << std::endl;
		std::cout << "ar3 size = " << ar3.size() << std::endl;
		std::cout << "ar3[0] = " << ar3[0] << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
