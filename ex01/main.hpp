/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:36:20 by msousa            #+#    #+#             */
/*   Updated: 2022/04/17 18:52:37 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAIN_H__
# define __MAIN_H__

# include <iostream>
# include <stdint.h>

# define LOG(x) std::cout << x << std::endl
# define ERROR(x) std::cerr << x << std::endl

struct Data
{
	char 	c;
    int 	i;
    float 	f;
    double 	d;
};

#endif
