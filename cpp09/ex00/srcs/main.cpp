/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:22:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/06/02 14:29:47 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/BitcoinExchange.hpp"


void	print_database(std::map<std::string, double> &db)
{
	std::map<std::string, double>::iterator it;
	it = db.begin();
	while(it != db.end())
	{
		std::cout << "Date: " << it->first << "$";
		std::cout << " Value: " << it->second << "$" << std::endl;
		it++;
	}
}

bool	parse_files(std::ifstream &input_file, std::ifstream &data)
{
	if (input_file.is_open() != 1)
	{
		std::cerr << "Error opening input file" << std::endl;
		return (false);
	}
	if (data.is_open() != 1)
	{
		std::cerr << "Error opening database" << std::endl;
		return (false);
	}
	return (true);
}

bool	parse_btc(std::string &date, std::string &value)
{
	if (date.empty() == true || value.empty() == true)
	{
		std::cerr << " empty ";
		return (false);
	}
	if (value.find_first_not_of("1234567890.") != value.npos || std::count(value.begin(), value.end(), '.') > 1)
	{
		std::cerr << " not a number ";
		return (false);
	}
	if (value == ".")
	{
		std::cerr << " just a dot ";
		return (false);
	}
	if (date.find_first_not_of("1234567890-") != date.npos)
	{
		std::cerr << " not a date ";
		return (false);
	}
	return (true);
}

bool make_database(std::map<std::string, double> &db, std::ifstream &data)
{
	std::string		date;
	std::string		value;
	std::string		line;
	std::getline(data, line);
	if (line.empty() == true)
	{
		std::cerr << "Database is empty!" << std::endl;
		return (false);
	}
	if (line != "date,exchange_rate")
	{
		std::cerr << "First line of database must be date,exchange_rate" << std::endl;
		return (false);
	}
	while (std::getline(data, line))
	{
		date = line.substr(0, line.find(','));
		value = line.substr(line.find(',') + 1);
		std::cout << date << "$ ";
		std::cout << value << "$";
		
		if (parse_btc(date, value) == true)
		{
			std::cout << "-> Insterted!!";
			db.insert(std::make_pair(date, std::strtod(value.c_str(), NULL)));
		}
		else
			std::cout << "-> Error!!";
		std::cout << std::endl; 
	}
	return (true);
}

bool	parse(char *input, std::map<std::string, double> &db)
{
	std::ifstream input_file(input);
	std::ifstream data("data.csv");
	if (parse_files(input_file, data) == false)
		return (false);
	if (make_database(db, data) == false)
		return (false);
	// print_database(db);
	return (true);
}
int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		std::cerr << "Invalid amount of arguments! ./bitcoin <input_file>" << std::endl;
		return (1);
	}
	std::map<std::string, double> db;
	if (parse(argv[1], db) == false)
		return (1);
}