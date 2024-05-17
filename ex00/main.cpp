/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:11:53 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/17 18:31:08 by bcarolle         ###   ########.fr       */
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
    std::ifstream   data("data.csv");
    std::ifstream   input(argv[1]);
    if (!data || !input)
    {
        if (!data)
            std::cerr << "Can't open data file" << std::endl;
        if (!input)
            std::cerr << "Can't open file from argument" << std::endl;
        return (2);
    }
}