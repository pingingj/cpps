/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:22:57 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/06/05 19:48:05 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/BitcoinExchange.hpp"

void	print_database(std::map<std::string, float> &db)
{
	std::map<std::string, float>::iterator it;
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

bool	parse_date(t_date &d)
{
	switch (d.month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if(d.day > 31)
				return (false);
			break;
		case 4: case 6: case 9: case 11:
			if(d.day > 30)
				return (false);
			break;
		case 2:
			if((d.year % 400 == 0) ||(d.year % 4 == 0 && d.year % 100 != 0))
			{
				if(d.day > 29)
					return(false);
			}
			else
			{
				if(d.day > 28)
					return(false);
			}
			break;
		default:
			return(false);
	}
	return (true);
}

bool	input_parse(std::string &date, std::string &value)
{
	if (strtod(value.c_str(), NULL) > 1000)
	{
		std::cerr << "Error: No values above 1000" << std::endl;
		return (false);
	}
	if ((value.find_first_not_of("1234567890. ") != value.npos || std::count(value.begin(), value.end(), '.') > 1))
	{
		std::cerr << "Error: Invalid value" << std::endl;
		return (false);
	}
	if ((date.find_first_not_of("1234567890- ") != date.npos || std::count(date.begin(), date.end(), '-') > 2))
	{
		std::cerr << "Error: Invalid date" << std::endl;
		return (false);
	}
	if ((std::count(value.begin(), value.end(), ' ') != 1 || std::count(date.begin(), date.end(), ' ') != 1 ||(*value.begin()) != ' ' || (*date.rbegin()) != ' '))
	{
		std::cerr << "Error: Input must have 1 space between pipe \"xxxx-xx-xx | x\"" << std::endl;
		return (false);
	}
	return (true);
}

bool	parse_btc(std::string &date, std::string &value, bool file)
{
	t_date d;
	std::cout << "date = " << date << "$ value = " << value << "$" << std::endl;
	if (date.empty() == true || value.empty() == true)
	{
		if (file == INPUT)
			std::cerr << "Error: Empty values" << std::endl;
		return (false);
	}
	if (file == DB && (value.find_first_not_of("1234567890.") != value.npos || std::count(value.begin(), value.end(), '.') > 1))
		return (false);
	if (file == DB && (date.find_first_not_of("1234567890-") != date.npos || std::count(date.begin(), date.end(), '-') > 2))
		return (false);
	if (strtod(value.c_str(), NULL) < 0)
	{
		if (file == INPUT)
			std::cerr << "Error: Not a positive value" << std::endl;
		return (false);
	}
	if (value.size() <= 1 || date.size() < 10)
	{
		std::cerr << "Error: Empty value" << std::endl;
		return (false);
	}
	if (file == INPUT && input_parse(date, value) == false)
		return (false);
	if (value == ".")
		return (false);
	d.year = strtod(date.substr(0, date.find('-')).c_str(), NULL);
	d.month = strtod(date.substr(date.find('-') + 1, date.find('-')).c_str(), NULL);
	d.day = strtod(date.substr(date.find('-') + 4).c_str(), NULL);
	if (parse_date(d) == false)
	{
		std::cerr << "Error: Invalid date" << std::endl;	
		return (false);
	}
	return (true);
}

bool make_database(std::map<std::string, float> &db, std::ifstream &data)
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
		std::cerr << "First line of database must be \"date,exchange_rate\"" << std::endl;
		return (false);
	}
	while (std::getline(data, line))
	{
		date = line.substr(0, line.find(','));
		value = line.substr(line.find(',') + 1);
		if (parse_btc(date, value, DB) == true)
			db.insert(std::make_pair(date, strtod(value.c_str(), NULL)));
	}
	return (true);
}

bool	parse(std::ifstream &input_file, std::map<std::string, float> &db)
{
	std::ifstream data("data.csv");
	if (parse_files(input_file, data) == false)
		return (false);
	if (make_database(db, data) == false)
		return (false);
	print_database(db);
	return (true);
}

void	search_btc(std::ifstream &input_file, std::map<std::string, float> &db)
{
	std::map<std::string, float>::iterator it;
	std::string	line;
	std::string	date;
	std::string	value;
	std::getline(input_file, line);
	if (line.empty())
	{
		std::cerr << "Input file is empty" << std::endl;
		return ;
	}
	if (line != "date | value")
	{
		std::cerr << "First line of inpute file must be \"date | value\"" << std::endl;
		return ;
	}
	while(std::getline(input_file, line))
	{
		date = line.substr(0, line.find('|'));
		value = line.substr(line.find('|') + 1);
		if (parse_btc(date, value, INPUT) == true)
		{
			it = db.upper_bound(date);
			if (it != db.begin())
			{
				it--;
				std::cout << it->first << " =>" << value << " = " << it->second * strtod(value.c_str(), NULL) << std::endl; 	
			}
			else
				std::cerr << date << " >= Error: Nothing found in database" << std::endl;
		}
	}
}

int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		std::cerr << "Invalid amount of arguments! ./bitcoin <input_file>" << std::endl;
		return (1);
	}
	std::map<std::string, float>	db;
	std::ifstream	input_file(argv[1]);
	std::cout << "------DB-------" << std::endl;
	if (parse(input_file, db) == false)
		return (1);
	std::cout << "------Input------" << std::endl;
	search_btc(input_file, db);
}