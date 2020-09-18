#pragma once
#include <iostream>

class Task3 
{
public:
	void Run()
	{
		std::cout << "Enter 'Hello': ";

		char* dest = new char[255];

		std::cin >> dest;

		std::cout << "\nResult concat: ";
		const char* src = "World";

		std::cout << strcat(dest, src) << std::endl;
	}
private:
	
	char* strcat(char* dest, const char* src)
	{
		size_t i, j;

		for (i = 0; dest[i] != '\0'; i++);

		for (j = 0; src[j] != '\0'; j++)
			dest[i + j] = src[j];

		dest[i + j] = '\0';

		return dest;
	}

};