#include <iostream>
#include <math.h>
#include "Vector.cpp"
#include "Matrix.cpp"
#include "Fraction.h"
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
	int num1 = 0, num2 = 0;
	char cf[] = "1/2";

	/* 
			Задание 1
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

	Matrix<float> tdArray = getMatrix(row, cell);
	
	std::cout << "\nMatrix: " << std::endl;
	for (size_t i = 0; i < tdArray.getRows(); i++)
	{
		for (size_t j = 0; j < tdArray.getCells(); j++)
		{
			std::cout << round(tdArray[i][j] * 100) / 100 << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << "\Vector: " << std::endl;
	Vector<float> arr = convertMatrix(tdArray, row, cell);

	for (size_t i = 0; i < row * cell; i++)
	{
		std::cout << round(arr[i] * 10000) / 10000 << " ";
	}

	/* Task 2
			Написать класс Fraction для представления обыкновенных дробей (как отношения
			двух целых чисел x/y). 
				Перегрузить операторы +, -, *, / для дробей. 
				Реализовать метод void reduce() для сокращения дроби, а также статические методы:
				int gcd(int n, int m) функция для нахождения наибольшего общего делителя чисел n и m;
				void printAsFraction(double decimal_fraction)
				void printAsFraction(char* decimal_fraction)
			перегруженные методы вывода десятичной дроби в виде обыкновенной
			(например, при значении decimal_fraction = 0.43 на экране должно
			вывестись 43/100, при 0.25 – 1/4 и т.д.).
				Также реализовать в виде статического члена класса счетчик всех созданных на
			данный момент в программе экземпляров дробей.
				Продемонстрировать работу созданного класса. Создать несколько объектов дробей.
				Произвести операции сложения, вычитания, умножения и деления дробей. Вывести
			на экран результаты. Показать также результаты работы статических методов класса
	*/

	std::cout << "\n\nEnter first fraction: "<<std::endl;
	std::cin >> num1;
	std::cout << "-\n";
	std::cin >> num2;
	Fraction f1(num1, num2);

	std::cout << "\nEnter second fraction: " << std::endl;
	std::cin >> num1;
	std::cout << "-\n";
	std::cin >> num2;
	Fraction f2(num1, num2);

	std::cout <<"\nCount of fraction: " << Fraction::countF() << std::endl;
	std::cout << "Common division " << Fraction::gcd(num1, num2) << std::endl;

	std::cout << "Division: " << f1 / f2 << std::endl;
	std::cout << "Multiply: " << f1 * f2 << std::endl;
	std::cout << "Difference: " << f1 - f2 << std::endl;
	std::cout << "Sum: " << f1 + f2 << std::endl;

	Fraction::printAsFraction(f1 / f2);

	Fraction::printAsFraction(1.44);
	
	Fraction::printAsFraction(cf);

	/* Task 3
	
	*/

}
