/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:07:40 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/27 23:28:44 by bcarolle         ###   ########.fr       */
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

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		
		bool	parseInput(std::ifstream &input);
		bool	parseData(std::ifstream &data);
		
		class WrongDataFile : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		void	findData(std::string date, float amount);
		std::map<std::string, float> _data;
		std::map<std::string, float> _input;
};
#endif
