/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:20:00 by msousa            #+#    #+#             */
/*   Updated: 2022/04/15 21:01:38 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cmath>

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

bool	is_char(std::string literal);
bool	is_int(std::string literal);
bool	is_float(std::string literal);
bool	is_double(std::string literal);

/* ----------------- */

bool	is_char(std::string literal)
{
	if (literal.length() != 1)
		return false;

	char c = literal.at(0);
	return !is_int(literal) && c >= 32 && c <= 126;
}

bool	is_int(std::string literal)
{
	// fails if value == 0 so safeguard before
	if (literal == "0")
		return true;

	char*	end;
    long	value = strtol(literal.c_str(), &end, 10);
    return 	value && *end == '\0';
}

bool	is_float(std::string literal)
{
	// if (literal == "-inff" || literal == "+inff" || literal == "nanf")
	// 	return true;
	size_t	dlength = literal.length() - 1;
	return literal.at(dlength) == 'f' && is_double(literal.substr(0, dlength));
}

bool	is_double(std::string literal)
{
	// if (literal == "-inf" || literal == "+inf" || literal == "nan")
	// 	return true;
	char*	end;
    double	value = strtod(literal.c_str(), &end);
    return 	end != literal.c_str() && *end == '\0' && value != HUGE_VAL;
}

e_type	get_type(std::string literal)
{
	t_tcheck	tchecks[4] = { is_char, is_int, is_float, is_double };

	for (size_t i = 0; i < 4; i++)
		if (tchecks[i](literal))
			return (e_type)(i + 1);
	return INVALID;
}

int	main( int argc, char* argv[] )
{
	if (argc != 2) {
		ERROR("1 scalar literal argument required");
		return 1;
	}

	// detect type of the literal passed as parameter
	e_type	type = get_type(argv[1]);

	if (type == INVALID) {
		ERROR("invalid type");
		return 1;
	}

	char	c = 0;
	int		i = 0;
	float	f = 0;
	double	d = 0;

	// convert it to its actual type
	// convert it to the three other types
	LOG(type);
	if (type == CHAR) {
		c = argv[1][0];
		i = c;
		f = c;
		d = c;
	} else if (type == INT) {
		i = std::atoi(argv[1]);
		c = i; //static_cast<char>(i);
		f = i;
		d = i;
	} else if (type == FLOAT) {
		f = std::atof(argv[1]);
		c = f;
		i = f;
		d = f;
	} else if (type == DOUBLE) {
		d = static_cast<double>(std::atof(argv[1]));
		c = d;
		i = d;
		f = d;
	}

	// display the results
	LOG("char: " << c);
	LOG("int: " << i);
	LOG("float: " << f);
	LOG("double: " << d);

	return 0;
}
