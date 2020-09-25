#include <iostream>
#include "Vector.cpp"
#include "Matrix.cpp"
#include <math.h>
/* Задание 1 
	Написать классы Vector и Matrix для хранения и обработки одномерных и
двумерных массивов, соответственно. Реализовать задание 2 лабораторной работы №1
с помощью созданных классов. Все функции оформить в виде методов классов.
В коде отразить следующее:
	1. Выделение и освобождение динамической памяти производить в конструкторах и
деструкторах классов, соответственно.
	2. В классе Vector перегрузить оператор индексации []. В классе Matrix добавить
методы T at(int i, int j) const и setAt(int i, int j, T val), которые
позволяют получить и установить значение элемента массива с индексом [i][j], T –
это тип элементов массива по варианту (int или double).
	3. Перегрузить операторы инкремента и декремента (как префиксного, так и
постфиксного). Смысл инкремента / декремента всего массива заключается в
инкременте / декременте каждого элемента массива.
*/
Vector<float> convertMatrix(Matrix<float> tdArray, const int sizeRow, const int sizeCell)
{
	Vector<float> arr(sizeRow * sizeCell);

	for (int i = 0, k = 0; i < sizeRow; i++)
	{
		for (int j = 0; j < sizeCell; j++)
		{
			arr[k] = tdArray[i][j];
			k++;
		}
	}

	return arr;
}

Matrix<float> getMatrix(const int sizeRow, const int sizeCell)
{
	Matrix<float> tdArray(sizeRow, sizeCell);

	for (size_t i = 0; i < sizeRow; i++)
	{
		for (size_t j = 0; j < sizeCell; j++)
		{
			tdArray[i][j] = sqrtf(i + j + 1);
		}
	}

	return tdArray;

}



int main()
{

	const int row = 4, cell = 4;
	Matrix<float> tdArray = getMatrix(row, cell);
	
	std::cout << "Matrix 2D array:" << std::endl;

	std::cout << "\n[ " << std::endl << std::endl;
	for (size_t i = 0; i < tdArray.getRows(); i++)
	{
		for (size_t j = 0; j < tdArray.getCells(); j++)
		{
			std::cout << round(tdArray[i][j] * 100) / 100 << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "\t\t\t   " << " ]" << std::endl;


	std::cout << "\n\nVector 1D array:" << std::endl;

	Vector<float> arr = convertMatrix(tdArray, row, cell);

	std::cout << "\n[ " << std::endl;
	for (size_t i = 0; i < row * cell; i++)
	{
		std::cout << round(arr[i] * 10000) / 10000 << " ";
	}
	std::cout << "\n]" << std::endl;

	std::cout << "\n2D Cells: " << tdArray.getCells()
		<< "\n2D Rows: " << tdArray.getRows()
		<< std::endl << std::endl;

	tdArray++;
	auto copyMatrix = tdArray;

	std::cout << "Post-increment Matrix:\n";

	for (size_t i = 0; i < tdArray.getRows(); i++)
	{
		for (size_t j = 0; j < tdArray.getCells(); j++)
		{
			std::cout << round(copyMatrix[i][j] * 100) / 100 << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	arr++;

	auto copyVector = arr;

	std::cout << "\nPost-increment Vector :\n ";

	for (size_t i = 0; i < arr.getSize(); i++)
	{
		std::cout << copyVector[i] << " ";
	}

	std::cout << std::endl;
}
