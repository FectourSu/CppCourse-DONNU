#pragma once
#include <math.h>
#include <cmath>
#include <iostream>

class Task2 
{
public:
	void Run()
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
		std::cout << "\t\t\t   " <<" ]" << std::endl;


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
private:
	float *convertToArray(float** tdArray, const int sizeRow, const int sizeCell)
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
				tdArray[i][j] = sqrt(i + j + 1);	
			}
		}

		return tdArray;

	}
	
	
};