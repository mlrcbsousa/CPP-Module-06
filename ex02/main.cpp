/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:20:00 by msousa            #+#    #+#             */
/*   Updated: 2022/04/20 22:37:55 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *	generate(void)
{
	Base * random = new A();

	return random;
}

void	identify(Base* p)
{
	(void)p;
	LOG("A");
}

void	identify(Base& p)
{
	// no pointer
	(void)p;
	LOG("A");
}

int main(void)
{
	Base * random = generate();

	identify(random);
	identify(*random);

    return (0);
}
