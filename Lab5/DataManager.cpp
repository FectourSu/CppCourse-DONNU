#include "DataManager.h"

template<class T>
inline DataManager<T>::DataManager()
{
	this->arr.reserve(maxSize);
}

template<class T>
void DataManager<T>::push(T elem)
{
	arr.push_back(elem);
	this->Serialize();
}

template<class T>
void DataManager<T>::push(T elems[], size_t n)
{
	for (size_t i = 0; i < n; i++)
		this->arr.push_back(elems[i]);

	if (maxSize < n)
	{
		this->Serialize();
		this->arr.clear();
	}
}


template<class T>
T DataManager<T>::peek()
{
	if (arr.size() % 2)
		return this->arr[0];

	return this->arr[arr.size() - 1 >> 1];
}

template<class T>
T DataManager<T>::pop()
{
	return this->arr[0];
}

template<class T>
void DataManager<T>::Serialize()
{
	std::ofstream out;

	out.open("dump.dat", std::ios::app | std::ios::out);

	if (out.is_open())	
		for (auto value : arr)
			out << value << std::endl;

	std::cout << "The array is written in dump.dat" << std::endl; 
}
