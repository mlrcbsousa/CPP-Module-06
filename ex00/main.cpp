/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:20:00 by msousa            #+#    #+#             */
/*   Updated: 2022/04/17 18:31:33 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

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
    return 	value && *end == '\0' && value >= INT_MIN && value <= INT_MAX;
}

bool	is_float(std::string literal)
{
	size_t	dlength = literal.length() - 1;
	return literal.at(dlength) == 'f' && is_double(literal.substr(0, dlength));
}

bool	is_double(std::string literal)
{
	char*	end;
    double	value = strtod(literal.c_str(), &end);
    return 	end != literal.c_str() && *end == '\0' && value;// != HUGE_VAL;
}

e_type	get_type(std::string literal)
{
	t_tcheck	tchecks[4] = { is_char, is_int, is_float, is_double };

	for (size_t i = 0; i < 4; i++)
		if (tchecks[i](literal))
			return (e_type)(i + 1);
	return INVALID;
}

void	print_impossible(std::string type) { LOG(type << ": impossible"); }
void	print_int(int d) { LOG("int: " << d); }

void	print_char(char c)
{
	if (std::isprint(c))
        LOG("char: '" << c << "'");
    else
        LOG("char: Non displayable");
}

void	print_float(float f)
{
	LOG("float: " << std::fixed << std::setprecision(1) << f << "f");
}

void	print_double(double d)
{
	LOG("double: " << std::fixed << std::setprecision(1) << d);
}

// convert it to the three other types
// display the results
void	print(char c)
{
	print_char(c);
	print_int(static_cast<int>(c));
	print_float(static_cast<float>(c));
	print_double(static_cast<double>(c));
}

void	print(int i)
{
	if (i < LimitsChar::min() || i > LimitsChar::max())
		print_impossible("char");
	else
		print_char(static_cast<char>(i));

	print_int(i);
	print_float(static_cast<float>(i));
	print_double(static_cast<double>(i));
}

void	print(float f)
{
	// A NaN never compares equal to itself.
	if (f < LimitsChar::min() || f > LimitsChar::max() || f != f)
		print_impossible("char");
	else
		print_char(static_cast<char>(f));

	if (f < LimitsInt::min() || f > LimitsInt::max() || f != f)
        print_impossible("int");
    else
        print_int(static_cast<int>(f));

	print_float(f);
	print_double(static_cast<double>(f));
}

void	print(double d)
{
	if (d < LimitsChar::min() || d > LimitsChar::max() || d != d)
		print_impossible("char");
	else
		print_char(static_cast<char>(d));

	if (d < LimitsInt::min() || d > LimitsInt::max() || d != d)
        print_impossible("int");
    else
        print_int(static_cast<int>(d));

	if (d < LimitsFloat::min() || d > LimitsFloat::max())
		print_impossible("float");
    else
        print_float(static_cast<float>(d));

	print_double(d);
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
		ERROR("invalid type or out of bounds");
		return 1;
	}

	// convert it to its actual type
	if (type == CHAR) {
		char	c = argv[1][0];
		print(c);
	} else if (type == INT) {
		char*	end;
    	int		i = strtol(argv[1], &end, 10);
		print(i);
	} else if (type == FLOAT) {
		char*	end;
    	float	f = static_cast<float>(strtod(argv[1], &end));
		print(f);
	} else if (type == DOUBLE) {
		char*	end;
    	double	d = strtod(argv[1], &end);
		print(d);
	}

	return 0;
}
