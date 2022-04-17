/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:36:20 by msousa            #+#    #+#             */
/*   Updated: 2022/04/17 18:27:57 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAIN_H__
# define __MAIN_H__

# include <iostream>
# include <iomanip>

# define LOG(x) std::cout << x << std::endl
# define ERROR(x) std::cerr << x << std::endl

enum e_type {
	INVALID,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
};

typedef bool (*t_tcheck)(std::string);

typedef std::numeric_limits<char>	LimitsChar;
typedef std::numeric_limits<int>	LimitsInt;
typedef std::numeric_limits<float>	LimitsFloat;

bool	is_char(std::string literal);
bool	is_int(std::string literal);
bool	is_float(std::string literal);
bool	is_double(std::string literal);

void	print(char c);
void	print(int i);
void	print(float f);
void	print(double d);


#endif
