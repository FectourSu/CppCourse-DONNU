#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include "Book.h"
#include <algorithm>

class Book
{
public:
	std::string Name;

	std::string Author;

	int Year;

	Book(std::string Name, std::string Author, int Year)
	{
		this->Name = Name;
		this->Author = Author;
		this->Year = Year;
	}

	std::string getAuthor()
	{
		return Author;
	}

	std::string getName()
	{
		return Name;
	}
};
