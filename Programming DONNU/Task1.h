#pragma once
#include <iostream>
#include "ExtendedArray.h"
#include <memory>


class Task1
{
public:
	void Run()
	{
		int b1 = 0, step = 0, size = 10;

		std::cout << "Enter initial element: ";
		std::cin >> b1;

		std::cout << "Enter step element: ";
		std::cin >> step;

		std::cout << "\nBasic array:" << std::endl;

		printBasicArray<int>(processArray(b1, step, size));
	}

private:
	template <typename T>
	void printBasicArray(ExtendedArray<T> mass)
	{
		for (size_t i = 0; i < mass.getSize(); i++)
		{

			std::cout << "mass[" << i << "] = " << mass[i] << std::endl;
		}
	}
	template <typename T>
	ExtendedArray<T> processArray(T initialElement, T step, const int size)
	{

		ExtendedArray<T> arr(size);
		
		arr.conditionArray(initialElement, step);
		
		CNT_element<T> object = arr.getCNTelements(initialElement, step);

		printBasicArray<T>(arr);

		std::cout << "\nThe number of three-digit numbers: " << object.value << std::endl << std::endl;

		ExtendedArray<int> arrSptr(size);

		std::cout << "Result array:" << std::endl;
		for (size_t i = 0; i < size; i++)
		{
			if (!(arr[i] % 3 == 1))
				arrSptr[i] = arr[i];
			else
				arrSptr[i] = 0;
		}

		return arrSptr;
	}
};

