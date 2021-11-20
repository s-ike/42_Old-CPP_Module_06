/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:41:01 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/20 21:53:18 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

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

	std::cout << "data address" << std::endl;
	std::cout << &data << std::endl;

	std::cout << "\nraw = serialize(&data); raw =" << std::endl;
	uintptr_t	raw = serialize(&data);
	std::cout << raw << std::endl;

	std::cout
		<< "\ndata2 = deserialize(raw);\n"
			"data2 address:" << std::endl;
	Data*	data2 = deserialize(raw);
	std::cout << data2 << std::endl;

	std::cout << "\ndata2->num()" << std::endl;
	std::cout << data2->num() << std::endl;
}
