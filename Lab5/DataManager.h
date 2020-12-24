#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <cctype>
#include <iterator>
#include <queue>
#include <algorithm>
#include <windows.h>

template <class T>
class DataManager
{
	std::vector<T> arr;
	int maxSize = 64;
	void Serialize();

public:
	DataManager();
	void push(T elem);	
	void push(T elems[], size_t n);
	T peek();
	T pop();
};

template <>
class DataManager<char>
{

	char mass_p[10] = { ',',';',':','.', '?', '!', '-', '(', ')', '"' };
	std::vector<char> arr;

public:

	void push(char value)
	{
		arr.push_back(value);

		if (scan(arr[arr.size() - 1]))
			arr[arr.size()- 1] = '_';
		
	}
	char popUpper()
	{
		return static_cast<char>(std::toupper(*arr.rbegin()));
	}
	char popLower()
	{
		return static_cast<char>(std::tolower(*arr.rbegin()));
	}
	bool scan(char item)
	{
		for (int i = 0; i < 10; i++)
			if (item == mass_p[i])
				return true;

		return false;
	}
};
