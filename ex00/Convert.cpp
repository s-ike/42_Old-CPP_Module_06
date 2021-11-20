/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:22:11 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/20 19:08:07 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>	// floor
#include "Convert.hpp"

/* ************************************************************************** */
/*   orthodox canonical form                                                  */
/* ************************************************************************** */

Convert::Convert()
{}

Convert::Convert(const std::string& input)
	:
	_input(input),
	_has_point(false),
	_is_special(false),
	_is_valid(is_valid_input()),
	_d()
{
	modify_input();
	to_double();
}

Convert::Convert(const Convert& other)
{
	*this = other;
}

Convert&	Convert::operator=(const Convert& other)
{
	if (this != &other)
	{
		_input = other._input;
	}
	return *this;
}

Convert::~Convert()
{}

/* ************************************************************************** */
/*   private methods                                                          */
/* ************************************************************************** */

bool	Convert::is_valid_input()
{
	const std::string	valid_strs[] = {
		"inff", "-inff", "+inff", "inf", "-inf", "+inf", "nanf", "nan"};
	for (size_t i = 0; i < sizeof(valid_strs) / sizeof(valid_strs[0]); i++)
		if (_input == valid_strs[i])
		{
			_is_special = true;
			return true;
		}

	size_t	size = _input.size();
	if (size == 1 && isprint(_input[0]))
		return true;

	if (_input == "-f" || _input == "+f")
		return false;
	size_t	i = 0;
	if (_input[0] == '-' || _input[0] == '+')
		i++;
	for (; i < size; i++)
	{
		if (_input[i] == '.')
		{
			if (!_has_point)
				_has_point = true;
			else
				return false;
		}
		else if (!(i == size - 1 && _input[i] == 'f')
			&& (!isdigit(_input[i]) || _input[i] == ' '))
		{
			return false;
		}
	}
	return true;
}

void	Convert::modify_input()
{
	if (!_is_special && 1 < _input.size() && _input[_input.size() - 1] == 'f')
	{
		_input.erase(_input.size() - 1, 1);
		return;
	}
	else if (!_is_special)
		return;

	const std::string	find_strs[] = {
		"inff", "-inff", "+inff", "nanf"};
	for (unsigned i = 0; i < sizeof(find_strs) / sizeof(find_strs[0]); i++)
	{
		if (_input == find_strs[i])
		{
			_input.erase(_input.size() - 1, 1);
			return;
		}
	}
}

void	Convert::to_double()
{
	if (_input.size() == 1 && !isdigit(_input[0]))
	{
		_d = static_cast<double>(_input[0]);
		return;
	}
	std::istringstream	is(_input);
	is >> _d;
	if (!is)
		_is_valid = false;
}

void	Convert::put_char()
{
	std::string	charstr;

	if (!_is_valid)
		charstr = "impossible";
	else if (_is_special || _d < std::numeric_limits<char>::min() || std::numeric_limits<char>::max() < _d)
		charstr = "impossible";
	else
	{
		char	c = static_cast<char>(_d);
		if (isprint(c))
			charstr = c;
		else
			charstr = "Non displayable";
	}
	std::cout << "char: " << charstr << std::endl;
}

void	Convert::put_int()
{
	std::string	intstr;

	if (!_is_valid)
		intstr = "impossible";
	else if (_is_special || _d < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < _d)
		intstr = "impossible";
	else
	{
		int	n = static_cast<int>(_d);
		std::ostringstream	os;
		os << n;
		intstr = os.str();
	}
	std::cout << "int: " << intstr << std::endl;
}

// void	Convert::put_float()
// {
// 	std::string	floatstr;

// 	if (!_is_valid)
// 		floatstr = "impossible";
// 	else
// 	{
// 		float	f = static_cast<float>(_d);
// 		std::ostringstream	os;
// 		os << f;
// 		floatstr = os.str();
// 		if (!_is_special && f != NAN && f != INFINITY && f != -INFINITY)
// 		{
// 			if (!_has_point || std::floor(f) == f)
// 				floatstr += ".0";
// 		}
// 		floatstr += "f";
// 	}
// 	std::cout << "float: " << floatstr << std::endl;
// }

void	Convert::put_float()
{
	std::string	floatstr;

	if (!_is_valid)
		floatstr = "impossible";
	else
	{
		float	f = static_cast<float>(_d);
		std::ostringstream	os;
		if (!_has_point || std::floor(f) == f)
			os << std::fixed << std::setprecision(1) << f;
		else
			os << std::fixed << std::setprecision(9) << f;
		floatstr = os.str();
		floatstr += "f";
	}
	std::cout << "float: " << floatstr << std::endl;
}

void	Convert::put_double()
{
	std::cout << "double: ";
	if (!_is_valid)
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	if (_d == INFINITY)
	{
		std::cout << "inf" << std::endl;
		return;
	}
	else if (_d == -INFINITY)
	{
		std::cout << "-inf" << std::endl;
		return;
	}
	if (!_is_special && std::floor(_d) == _d)
		std::cout << std::fixed << std::setprecision(1) << _d;
	else
		std::cout << std::fixed << std::setprecision(17) << _d;
	std::cout << std::endl;
}

/* ************************************************************************** */
/*   public methods                                                           */
/* ************************************************************************** */

void	Convert::display_result()
{
	put_char();
	put_int();
	put_float();
	put_double();
}
