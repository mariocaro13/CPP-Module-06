/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:55:11 by mcaro-ro          #+#    #+#             */
/*   Updated: 2026/03/27 20:06:16 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"
#include <iostream>

int main()
{
	Base *base = generate();

	std::cout << "Identifying with pointer:" << std::endl;
	identify(base);

	std::cout << "Identifying with reference:" << std::endl;
	identify(*base);

	delete base;
	return (0);
}
