/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:28:14 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/29 00:30:09 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./RPN [Math expression]" << std::endl;
        return 1;
    }
    std::string input = argv[1];
    RPN rpn;
    try
    {
        rpn.parse(input);
        rpn.calculate();
        rpn.printResult();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}