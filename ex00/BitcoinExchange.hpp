/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:07:40 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/18 15:10:18 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <exception>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		
		bool	parseInput(std::ifstream &input);
		bool	parseData(std::ifstream &data);
		
	private:
		std::map<std::string, float> _data;
		std::map<std::string, float> _input;
};
#endif
