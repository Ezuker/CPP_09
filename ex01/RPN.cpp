/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:28:11 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/29 19:56:54 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &cpy)
{
	*this = cpy;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		this->_numbers = rhs._numbers;
	}
	return *this;
}

static bool isOperation(char c)
{
	return (c == '+' || c == '*' || c == '/' || c == '-');
}

void RPN::doOperation(char c)
{
	if (this->_numbers.size())
	{
		int tmp = this->_numbers.top();
		this->_numbers.pop();
		if (this->_numbers.size())
		{
			int tmp2 = this->_numbers.top();
			this->_numbers.pop();
			switch (c)
			{
				case '*':
					this->_numbers.push(tmp2 * tmp);
					break;
				case '/':
					this->_numbers.push(tmp2 / tmp);
					break;
				case '+':
					this->_numbers.push(tmp2 + tmp);
					break;
				case '-':
					this->_numbers.push(tmp2 - tmp);
					break;
			}
		}
		else
			throw std::logic_error("Wrong input");
	}
	else
		throw std::logic_error("Wrong input");
}

void RPN::parse(std::string input)
{
	bool	isSpace = false;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]) && !isSpace)
		{
			this->_numbers.push(input[i] - '0');
			isSpace = true;
		}
		else if (isOperation(input[i]) && !isSpace)
		{
			doOperation(input[i]);
			isSpace = true;
		}
		else if (input[i] == ' ')
		{
			isSpace = false;
			continue;
		}
		else
			throw std::logic_error("Wrong input");
	}
	if (this->_numbers.size() != 1)
		throw std::logic_error("Wrong input");
}

void	RPN::printResult()
{
	std::cout << this->_numbers.top() << std::endl;
}
