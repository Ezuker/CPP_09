/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:28:11 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/29 01:23:16 by bcarolle         ###   ########.fr       */
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
        this->_operation = rhs._operation;
        this->_numbers = rhs._numbers;
    }
    return *this;
}

static bool isOperation(char c)
{
    return (c == '+' || c == '*' || c == '/' || c == '-');
}

void RPN::parse(std::string input)
{
    bool    isSpace = false;
    for (size_t i = 0; i < input.length(); i++)
    {
        if (isdigit(input[i]) && !isSpace)
        {
            this->_numbers.push(input[i] - '0');
            isSpace = true;
        }
        else if (isOperation(input[i]) && !isSpace)
        {
            this->_operation.push(input[i]);
            isSpace = true;
        }
        else if (input[i] == ' ' && isSpace)
        {
            isSpace = false;
            continue;
        }
        else
            throw std::logic_error("Wrong input");
    }
    if (this->_operation.size() != this->_numbers.size() - 1)
        throw std::logic_error("Wrong input");
}

void    RPN::calculate()
{
    int tmp;
    int tmp2;
    std::stack<char> operations;
    std::stack<int> numbers;
    while (!this->_numbers.empty())
    {
        numbers.push(this->_numbers.top());
        this->_numbers.pop();
    }
    while (!this->_operation.empty())
    {
        operations.push(this->_operation.top());
        this->_operation.pop();
    }
    while (operations.size())
    {
        tmp = numbers.top();
        numbers.pop();
        tmp2 = numbers.top();
        numbers.pop();
        switch (operations.top())
        {
            case '*':
                numbers.push(tmp * tmp2);
                break;
            case '/':
                numbers.push(tmp / tmp2);
                break;
            case '+':
                numbers.push(tmp + tmp2);
                break;
            case '-':
                numbers.push(tmp - tmp2);
                break;
        }
        operations.pop();
    }
    this->_numbers.push(numbers.top());
}

void    RPN::printResult()
{
    std::cout << this->_numbers.top() << std::endl;
}