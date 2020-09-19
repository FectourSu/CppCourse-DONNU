#include <iostream>
#include <memory>
#include <math.h>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

/*Задание 1
Объявить массив из n = 10 целых чисел, проинициализировать нулями. Функция processArray()
должна заполнить массив членами геометрической прогрессии с начальным элементом b1 и шагом q
(ввести с клаиватуры), подсчитать и вернуть cnt - количество всех трёзначных элементов массива,
а так же сформировать выходной массив, который содержит все элементы исходного, кроме тех, которые
делятся на 3 с остатком 1. Вывести на экран массивы.
*/

void printBasicArray(int* mass, const int size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("\nmass[ %d ] = ", (int)i);
		printf("%d", mass[i]);
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

	printBasicArray(mass, size);

	int valueCNT = NULL;
	temp = 0;

	while (temp < size)
	{
		if (mass[temp] < 1000 &&
			mass[temp] > 99)
			valueCNT++;
		temp++;
	}

	printf("\nThe number of three-digit numbers: %d \n", valueCNT);

	int* arrSptr = new int[size];
	temp = 0;

	printf("\nResult array:\n");

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

void RunTask1()
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

	printBasicArray(mass, size);

	delete[] mass;
}


/*
Преобразование: 2D -> 1D. Двумерный массив 4х4 вещественных чисел необходимо
выложить в один ряд по элементам справа налево и сверху вниз.
Инициализация: запонить массив числами x[i][j] = sqrt(i+j+1);
Вывод на экран: каждый элемент одномерного массива вывести с точностью 4 знака
после запятой; каждый элемент двумерного массива - с точностью 2 знака.
*/
float* convertToArray(float** tdArray, const int sizeRow, const int sizeCell)
{
	float* arr = new float[sizeRow * sizeCell];

	for (size_t i = 0, k = 0; i < sizeRow; i++)
	{
		for (size_t j = 0; j < sizeCell; j++)
		{
			arr[k] = tdArray[i][j];
			k++;
		}
	}

	return arr;
}

float** getDarray(const int sizeRow, const int sizeCell)
{
	float** tdArray = new float* [sizeRow];

	for (size_t i = 0; i < sizeRow; i++)
	{
		tdArray[i] = new float[sizeCell];
	}

	for (size_t i = 0; i < sizeRow; i++)
	{
		for (size_t j = 0; j < sizeCell; j++)
		{
			tdArray[i][j] = sqrtf(i + j + 1);
		}
	}

	return tdArray;

}

void RunTask2()
{
	const int row = 4, cell = 4;
	float** tdArray = getDarray(row, cell);

	std::cout << "Default 2D array:" << std::endl;

	std::cout << "\n[ " << std::endl << std::endl;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < cell; j++)
		{
			std::cout << round(tdArray[i][j] * 100) / 100 << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "\t\t\t   " << " ]" << std::endl;


	std::cout << "\n\nNew 1D array:" << std::endl;

	float* arr = convertToArray(tdArray, row, cell);

	std::cout << "\n[ " << std::endl;
	for (size_t i = 0; i < row * cell; i++)
	{
		std::cout << round(arr[i] * 10000) / 10000 << " ";
	}
	std::cout << "\n]" << std::endl;

	for (size_t i = 0; i < row; i++)
	{
		delete[] tdArray[i];
	}
	delete[] arr;
	delete[] tdArray;
}

/*
Функция strcat.
Формат: char* strcat(char* dest, const char* src).
Функция приписывает строку src к строке dest.
*/

char* Strcat(char* dest, const char* src)
{
	size_t i, j;

	for (i = 0; dest[i] != '\0'; i++);

	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	dest[i + j] = '\0';

	return dest;
}

void RunTask3()
{
	printf("Enter 'Hello': ");

	char* dest = new char[255];
	const char* src = "World";

	scanf_s("%s", dest);

	char* temp = new char[255];
	memcpy(temp, dest, 255);

	printf("\nResult concat(my function): ");

	printf("%s",Strcat(dest, src));

	printf("\nResult concat(default function): ");

	strcat_s(temp, 255, src);

	printf("%s\n", temp);

	delete[] dest;
	delete[] temp;
}

int main()
{
tryAgain:
	system("cls");
	std::cout << "Select Task: (from 1 to 3, 4 - exit)" << std::endl;

	int userSelect = 0;
	std::string userAction;

	// action
	std::cin >> userSelect;

	while (true)
	{
		if (userSelect == 1)
		{
			system("cls");
			RunTask1();
		}
		else if (userSelect == 2)
		{
			system("cls");
			RunTask2();
		}
		else if (userSelect == 3)
		{
			system("cls");
			RunTask3();
		}
		else if (userSelect == 4)
			return 0;
		else
		{
			system("cls");
			std::cout << "There is no such option" << std::endl;
			goto tryAgain;
		}
		//walk to program
	Select:
		std::cout << "\nWant to continue? (Y / N): ";
		std::cin >> userAction;
		
		if (userAction == "Y")
			goto tryAgain;
		else if (userAction == "N")
			return 0;
		else
		{
			std::cout << "There is no such option." << std::endl;
			goto Select;
		}
	}
}
