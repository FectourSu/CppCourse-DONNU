#pragma once
#include <memory>
#include "CNTelement.h"
#include <math.h>

template <typename T>
class ExtendedArray
{
public:
	ExtendedArray(int size);

	int getSize();
	CNT_element<T> getCNTelements(T b1, T q);
	void conditionArray(T initialElement, T step);
 

	T& operator [](size_t i) const;

private:
	int size;
	std::shared_ptr<T[]> arrSptr;
};

template<typename T>
ExtendedArray<T>::ExtendedArray(int size)
{
	 this->size = size;
	 this->arrSptr = std::shared_ptr<T[]>(new T[size]);
}

template<typename T>
T& ExtendedArray<T>::operator[](size_t i) const
{
	return this->arrSptr[i];
}

template<typename T>
int ExtendedArray<T>::getSize()
{
	return this->size;
}

template<typename T>
CNT_element<T> ExtendedArray<T>::getCNTelements(T b1, T q)
{
	T valueCNT = NULL;

	for (size_t i = 0; i < size; i++)
		if (this->arrSptr[i] < 1000 && 
			this->arrSptr[i] > 99)
			valueCNT++;

	return  CNT_element<T>(valueCNT);
}

template<typename T>
void ExtendedArray<T>::conditionArray(T initialElement, T step)
{
	T result = initialElement;

	size_t temp = 0;

	while (temp < size)
	{
		this->arrSptr[temp] = result;	
		result *= step;
	
		temp++;
	}
}


