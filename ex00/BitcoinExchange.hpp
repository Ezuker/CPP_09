/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:07:40 by bcarolle          #+#    #+#             */
/*   Updated: 2024/06/22 16:38:56 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <exception>
# include <string>
# include <stdlib.h>
# include <sstream>
# include <iomanip>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpy);
		~BitcoinExchange();

		BitcoinExchange	&operator=(const BitcoinExchange &rhs);
		
		bool	parseInput(std::ifstream &input);
		bool	parseData(std::ifstream &data);
		
		class WrongDataFile : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		void	findData(std::string date, long double amount);
		std::map<std::string, float> _data;
		std::map<std::string, float> _input;
};
#endif
