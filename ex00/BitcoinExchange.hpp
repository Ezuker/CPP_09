/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:07:40 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/17 18:58:11 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange(std::string input);
        ~BitcoinExchange();
        
        bool    checkInput();
        
    private:
        std::map<std::string, float> _data;
};
#endif