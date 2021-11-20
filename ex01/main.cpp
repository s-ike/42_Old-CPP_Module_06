/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:41:01 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/20 22:37:04 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

#define COLOR_RESET	"\033[m"
#define COLOR_CYAN	"\033[36m"

void	print_header(const std::string &str)
{
	std::cout << COLOR_CYAN << "\n[ " << str << " ]" << COLOR_RESET << std::endl;
}

uintptr_t	serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int	main()
{
	Data	data(100);

	print_header("data address");
	std::cout << &data << std::endl;

	print_header("raw = serialize(&data); raw =");
	uintptr_t	raw = serialize(&data);
	std::cout << raw << std::endl;

	print_header("data2 = deserialize(raw); data2 address:");
	Data*	data2 = deserialize(raw);
	std::cout << data2 << std::endl;

	print_header("data2->num()");
	std::cout << data2->num() << std::endl;
}
