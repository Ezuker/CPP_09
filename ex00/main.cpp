/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:11:53 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/18 15:08:24 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (22);
	}

	std::string input = argv[1];
	std::ifstream data_stream("data.csv");
	if (!data_stream)
	{
		std::cerr << "Can't open data file" << std::endl;
		return (2);
	}
	std::ifstream input_stream("input");
	if (!input_stream)
	{
		std::cerr << "Can't open input file" << std::endl;
		return (2);
	}
	
	BitcoinExchange	btc;
	try
	{
		btc.parseData(data_stream);
		btc.parseInput(input_stream);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
