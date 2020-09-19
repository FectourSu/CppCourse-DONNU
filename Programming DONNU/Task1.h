#pragma once
#include <iostream>
#include <memory>

/*
�������� ������ �� n = 10 ����� �����, ������������������� ������. ������� processArray()
������ ��������� ������ ������� �������������� ���������� � ��������� ��������� b1 � ����� q
(������ � ����������), ���������� � ������� cnt - ���������� ���� ��������� ��������� �������,
� ��� �� ������������ �������� ������, ������� �������� ��� �������� ���������, ����� ���, �������
������� �� 3 � �������� 1. ������� �� ����� �������.
*/


class Task1
{
public:
	void Run()
	{
		int b1 = 0, step = 0;
		const int size = 10;

		std::cout << "Enter initial element: ";
		std::cin >> b1;

		std::cout << "Enter step element: ";
		std::cin >> step;

		std::cout << "\nBasic array:" << std::endl;

		int arr[size];

		int* mass = processArray(arr, b1, step, size);

		printBasicArray<int>(mass, size);

		delete[] mass;
	}

private:
	template <typename T>
	void printBasicArray(T* mass, const int size)
	{
		for (size_t i = 0; i < size; i++)
		{

			std::cout << "mass[" << i << "] = " << mass[i] << std::endl;
		}
	}

	int* processArray(int* mass, int initialElement, int step, const int size)
	{
		int result = initialElement;

		size_t temp = 0;

		while (temp < size)
		{
			mass[temp] = result;
			result *= step;

			temp++;
		}
		
		printBasicArray<int>(mass, size);

		int valueCNT = NULL;
		temp = 0;

		while (temp < size)
		{
			if (mass[temp] < 1000 &&
				mass[temp] > 99)
				valueCNT++;
			temp++;
		}

		std::cout << "\nThe number of three-digit numbers: " << valueCNT << std::endl << std::endl;

		int* arrSptr = new int[size];
		temp = 0;

		std::cout << "Result array:" << std::endl;

		while (temp < size)
		{
			if (!(mass[temp] % 3 == 1))
				arrSptr[temp] = mass[temp];
			else
				arrSptr[temp] = 0;
			temp++;
		}


		return arrSptr;
	}
};

