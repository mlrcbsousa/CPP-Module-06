/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:20:00 by msousa            #+#    #+#             */
/*   Updated: 2022/04/17 18:53:25 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

uintptr_t	serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*	deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

int main(void)
{
    Data 		data = {'a', 3, 3.6f, 8.23};
	uintptr_t 	raw;
	Data* 		ptr;

    raw = serialize(&data);
    ptr = deserialize(raw);

    LOG("c: " << ptr->c);
    LOG("i: " << ptr->i);
    LOG("f: " << ptr->f);
    LOG("d: " << ptr->d);

    LOG("&data : " << &data);
    LOG("ptr   : " << ptr);

    return (0);
}
