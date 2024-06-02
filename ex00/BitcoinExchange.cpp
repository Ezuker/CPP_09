/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:07:31 by bcarolle          #+#    #+#             */
/*   Updated: 2024/06/02 19:17:28 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{}

static bool	validDate(std::string date)
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}
	std::stringstream ss(date);
	int year, month, day;
	char dash;
	ss >> year >> dash >> month >> dash >> day;
	if (month < 1 || month > 12)
		return false;
	if (day < 1)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2)
	{
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if ((isLeapYear && day > 29) || (!isLeapYear && day > 28))
			return false;
	}
	if (day > 31)
		return false;
	return true;

}
bool	BitcoinExchange::parseData(std::ifstream &data)
{
	std::string first;
	std::getline(data, first);
	if (first != "date,exchange_rate")
		throw WrongDataFile();
	while (data)
	{
		std::string line;
		std::getline(data, line);
		if (line.empty())
			break;
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			throw WrongDataFile();
		std::string date = line.substr(0, pos);
		std::string rate = line.substr(pos + 1);
		if (date.empty() || rate.empty())
			throw WrongDataFile();
		_data[date] = std::strtold(rate.c_str(), NULL);
	}
	if (_data.empty())
		throw WrongDataFile();
	for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++)
	{
		if (!validDate(it->first))
			throw WrongDataFile();
		if (it->second < 0)
			throw WrongDataFile();
	}
	return true;
}

void	BitcoinExchange::findData(std::string date, long double amount)
{
	std::map<std::string, float>::iterator it = _data.lower_bound(date);
	if (it->first == date)
	{
		std::cout << date << " => " << amount << " = " << it->second * amount << std::endl;
		return;
	}
	if (it != _data.begin())
	{
		it--;
		std::cout << date << " => " << amount << " = " << it->second * amount << std::endl;
		return;
	}
	if (date < _data.begin()->first)
	{
		std::cout << date << " => " << amount << " = " << _data.begin()->second * amount << std::endl;
		return;
	}
}

bool	BitcoinExchange::parseInput(std::ifstream &input)
{
	std::string first;
	std::getline(input, first);
	if (first != "date | value")
	{
		std::cout << "Need \"date | value\"" << std::endl;
		return false;
	}
	while (input)
	{
		std::string line;
		std::getline(input, line);
		if (line.empty())
			continue;
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, pos - 1);
		if (!validDate(date))
		{
			std::cout << "Error: bad date => " << line << std::endl;
			continue;
		}
		long double amount = std::strtold(line.substr(pos + 1).c_str(), NULL);
		if (amount > 2147483647.0)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		if (amount < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		findData(date, amount);
	} 
	return true;
}

const char* BitcoinExchange::WrongDataFile::what() const throw()
{
	return "Error while parsing data file";
}
