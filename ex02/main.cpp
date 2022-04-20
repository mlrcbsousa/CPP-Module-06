/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:20:00 by msousa            #+#    #+#             */
/*   Updated: 2022/04/20 23:11:34 by msousa           ###   ########.fr       */
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
		case 0 : random = new A; break;
		case 1 : random = new B; break;
		case 2 : random = new C; break;
	}

	return random;
}

void	identify(Base* p)
{
	A * a = dynamic_cast<A *>(p);

	if (!a) {
		B * b = dynamic_cast<B *>(p);

		if (!b) {
			C * c = dynamic_cast<C *>(p);

			if (!c) {

			} else { LOG("C"); }
		} else { LOG("B"); }
	} else { LOG("A"); }
}

void	identify(Base& p)
{
	try {
		A & a = dynamic_cast<A &>(p);
		(void)a;
		LOG("A");
	}
	catch (std::bad_cast & e) {
		(void)e;
		try {
			B & b = dynamic_cast<B &>(p);
			(void)b;
			LOG("B");
		}
		catch (std::bad_cast & e) {
			(void)e;
			try {
				C & c = dynamic_cast<C &>(p);
				(void)c;
				LOG("C");
			}
			catch (std::bad_cast & e) {
				e.what();
			}
		}
	}
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
