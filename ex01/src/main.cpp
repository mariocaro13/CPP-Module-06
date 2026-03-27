/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:29:42 by mcaro-ro          #+#    #+#             */
/*   Updated: 2026/03/27 19:45:07 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

void basicTest()
{
	std::cout << "=== Basic Test ===\n" << std::endl;

	Data data;
	data.name = "Alice";
	data.age = 30;

	std::cout << "Original Data:" << std::endl;
	std::cout << "Name: " << data.name << ", Age: " << data.age << std::endl;

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "\nSerialized Data (uintptr_t): " << serialized << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "Name: " << deserialized->name << ", Age: " << deserialized->age << std::endl;
}

void multipleObjectsTest()
{
	std::cout << "\n=== Multiple Objects Test ===\n" << std::endl;

	Data data1;
	data1.name = "Bob";
	data1.age = 25;

	Data data2;
	data2.name = "Charlie";
	data2.age = 35;

	uintptr_t serialized1 = Serializer::serialize(&data1);
	uintptr_t serialized2 = Serializer::serialize(&data2);

	std::cout << "Serialized Data 1 (uintptr_t): " << serialized1 << std::endl;
	std::cout << "Serialized Data 2 (uintptr_t): " << serialized2 << std::endl;

	Data* deserialized1 = Serializer::deserialize(serialized1);
	Data* deserialized2 = Serializer::deserialize(serialized2);

	std::cout << "\nDeserialized Data 1:" << std::endl;
	std::cout << "Name: " << deserialized1->name << ", Age: " << deserialized1->age << std::endl;

	std::cout << "\nDeserialized Data 2:" << std::endl;
	std::cout << "Name: " << deserialized2->name << ", Age: " << deserialized2->age << std::endl;
}

int main()
{
	basicTest();
	multipleObjectsTest();
	return (0);
}
