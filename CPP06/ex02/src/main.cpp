/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:16:42 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/01 17:07:28 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

static Base*	generate()
{
	Base *ptr = NULL;
	
	size_t randomBase = rand() % 3;

	switch (randomBase)
	{
	case A_BASE:
		ptr = new A;
		break;
	case B_BASE:
		ptr = new B;
		break;
	case C_BASE:
		ptr = new C;
		break;
	default:
		break;
	}
	return (ptr);
}

static void	identify(Base* p)
{
	try
	{
		dynamic_cast<A*>(p);
		std::cout << "Type is A" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl; 
	}

	try
	{
		dynamic_cast<B*>(p);
		std::cout << "Type is B" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl; 
	}

	try
	{
		dynamic_cast<C*>(p);
		std::cout << "Type is C" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl; 
	}
}

static void	identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "Type is A" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl; 
	}
	
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "Type is B" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl; 
	}

	try
	{
		dynamic_cast<C&>(p);
		std::cout << "Type is C" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl; 
	}
}

int main(void)
{
    Base *basePtr = generate();
    
    identify(basePtr);
    identify(*basePtr);

    return (0);
}
