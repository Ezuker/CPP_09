/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:56:58 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/31 14:20:02 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe	merge;

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
		merge.sortDeque();
		merge.sortVector();
		std::cout << "After: ";
		merge.printContainer();
		merge.printPerf();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
