/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:07:31 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/27 01:50:34 by bcarolle         ###   ########.fr       */
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
	if (year < 2009 || year > 2024)
		return false;
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

bool	BitcoinExchange::parseInput(std::ifstream &input)
{
	std::string first;
	std::getline(input, first);
	while (input)
	{
		std::string line;
		std::getline(input, line);
		if (line.empty())
			break;
		size_t pos = line.find('|');
		if (pos == std::string::npos)
			throw WrongDataFile();
		std::string date = line.substr(0, pos);
		std::string amount = line.substr(pos + 1);
		if (date.empty() || amount.empty())
			throw WrongDataFile();
		_input[date] = std::strtold(amount.c_str(), NULL);
	}
	return true;
}

const char* BitcoinExchange::WrongDataFile::what() const throw()
{
	return "Error while parsing data file";
}