/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:56:58 by bcarolle          #+#    #+#             */
/*   Updated: 2024/06/01 01:51:56 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe merge;

    if (argc == 1)
    {
        std::cout << "Wrong number of argument" << std::endl;
        return 22;
    }
    try
    {
        merge.parseInput(argv);
        std::cout << "Before: ";
        merge.printContainer();
        merge.sort();
        std::cout << "After: ";
        merge.printContainer();
        merge.printPerf();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}