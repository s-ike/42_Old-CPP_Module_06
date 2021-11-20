/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:10:27 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/20 22:33:14 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>	// time
#include <cstdlib>	// srand,rand
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#define COLOR_RESET	"\033[m"
#define COLOR_CYAN	"\033[36m"

void	print_header(const std::string &str)
{
	std::cout << COLOR_CYAN << "\n[ " << str << " ]" << COLOR_RESET << std::endl;
}

Base * generate(void)
{
	srand(time(NULL));
	switch (rand() % 3)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	}
	return NULL;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << 'A' << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << 'B' << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << 'C' << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A	temp = dynamic_cast<A&>(p);
		std::cout << 'A' << std::endl;
		return;
	}
	catch (std::bad_cast)
	{}
	try
	{
		B	temp = dynamic_cast<B&>(p);
		std::cout << 'B' << std::endl;
		return;
	}
	catch (std::bad_cast)
	{}
	try
	{
		C	temp = dynamic_cast<C&>(p);
		std::cout << 'C' << std::endl;
		return;
	}
	catch (std::bad_cast)
	{}
	std::cout << "Unknown type" << std::endl;
}

int	main()
{
	print_header("generate()");
	Base*	test = generate();

	print_header("void identify(Base* p)");
	identify(test);

	print_header("void identify(Base& p)");
	identify(*test);
}
