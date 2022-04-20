/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:20:00 by msousa            #+#    #+#             */
/*   Updated: 2022/04/20 22:51:51 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *	generate(void)
{
	Base * random;

	int type = rand() % 3;

	switch(type) {
		case 0 :
			random = new A;
			LOG("A");
			break;
		case 1 :
			random = new B;
			LOG("B");
			break;
		case 2 :
			random = new C;
			LOG("C");
			break;
	}

	return random;
}

void	identify(Base* p)
{
	(void)p;
}

void	identify(Base& p)
{
	// no pointer
	(void)p;
}

int main(void)
{
	// set seed for random number generator
	std::srand((unsigned int)time(NULL));

	Base * random = generate();

	identify(random);
	identify(*random);

    return (0);
}
