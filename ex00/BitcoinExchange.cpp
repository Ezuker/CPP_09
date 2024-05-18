/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:07:31 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/18 15:21:24 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{}

bool	BitcoinExchange::parseData(std::ifstream &data)
{
	std::getline(data);
	return true;
}

bool	BitcoinExchange::parseInput(std::ifstream &input)
{
	(void)input;
	return true;
}
