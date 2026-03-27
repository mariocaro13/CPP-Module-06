/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:41:10 by mcaro-ro          #+#    #+#             */
/*   Updated: 2026/03/27 18:49:23 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(const std::string& literal)
{
	return (literal.length() == 1 && !std::isdigit(literal[0]));
}

static bool isInt(const std::string& literal)
{
	char* endptr;
	std::strtol(literal.c_str(), &endptr, 10);
	return (*endptr == '\0');
}

static bool isFloat(const std::string& literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return (true);
	
	char* endptr;
	std::strtof(literal.c_str(), &endptr);
	return (*endptr == 'f' && *(endptr + 1) == '\0');
}

static bool isDouble(const std::string& literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return (true);
	
	char* endptr;
	std::strtod(literal.c_str(), &endptr);
	return (*endptr == '\0');
}

static bool isPseudoLiteral(const std::string& literal)
{
	return (literal == "nan" || literal == "+inf" || literal == "-inf" ||
			literal == "nanf" || literal == "+inff" || literal == "-inff");
}


static void convertChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void convertInt(const std::string& literal)
{
	int i = std::atoi(literal.c_str());

	std::cout << "char: ";
	if (i < 0 || i > 127)
		std::cout << "impossible";
	else if (i >= 32 && i <= 126)
		std::cout << "'" << static_cast<char>(i) << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

static void convertFloat(const std::string& literal)
{
	float f = std::strtof(literal.c_str(), NULL);

	std::cout << "char: ";
	if (std::isnan(f) || f < 0 || f > 127)
		std::cout << "impossible";
	else if (f >= 32 && f <= 126)
		std::cout << "'" << static_cast<char>(f) << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;

	std::cout << "int: ";
	if (std::isnan(f) || f > static_cast<float>(std::numeric_limits<int>::max()) || f < static_cast<float>(std::numeric_limits<int>::min()))
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(f);
	std::cout << std::endl;

	std::cout << "float: " << f;
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(f);
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << std::endl;
}

static void convertDouble(const std::string& literal)
{
	double d = std::strtod(literal.c_str(), NULL);

	std::cout << "char: ";
	if (std::isnan(d) || d < 0 || d > 127)
		std::cout << "impossible";
	else if (d >= 32 && d <= 126)
		std::cout << "'" << static_cast<char>(d) << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;

	std::cout << "int: ";
	if (std::isnan(d) || d > static_cast<double>(std::numeric_limits<int>::max()) || d < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(d);
	std::cout << std::endl;
	
	std::cout << "float: " << static_cast<float>(d);
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << d;
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << std::endl;
}

static void printPseudoLiteral(const std::string& literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (literal[literal.length() - 1] == 'f')
		std::cout << "float: " << literal << std::endl;
	else
		std::cout << "float: " << literal << "f" << std::endl;

	std::cout << "double: " << (literal[literal.length() - 1] == 'f' ? literal.substr(0, literal.length() - 1) : literal) << std::endl;
}


ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

void ScalarConverter::convert(const std::string& literal)
{
	if (isPseudoLiteral(literal))
		printPseudoLiteral(literal);
	else if (isChar(literal))
		convertChar(literal[0]);
	else if (isInt(literal))
		convertInt(literal);
	else if (isFloat(literal))
		convertFloat(literal);
	else if (isDouble(literal))
		convertDouble(literal);
	else
		std::cout << "Error: Invalid literal" << std::endl;
}
