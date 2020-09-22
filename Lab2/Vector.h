#pragma once
template<typename T>
class Vector {
private:
	T* inputArr;
	int sizeArray;


	void incrementArr();
	void decrementArr();

public:
	//ctor deep copy
	Vector(const Vector<T> &adrs);
	Vector(int size);
	~Vector();

	int getSize();

	T& operator [](int i) const;

	//pre-increment
	Vector<T>& operator++();
	Vector<T>& operator--();

	//post-increment
	Vector<T> operator--(int);
	Vector<T> operator++(int);
};


template<typename T>
inline Vector<T>::Vector(const Vector<T>& adrs)
{
	this->sizeArray = adrs.sizeArray;
	this->inputArr = new T[sizeArray];

	for (size_t i = 0; i < sizeArray; i++)
	{
		this->inputArr[i] = adrs.inputArr[i];
	}
}

template<typename T>
Vector<T>::Vector(int size)
{
	this->sizeArray = size;
	this->inputArr = new T[sizeArray];
}

template<typename T>
Vector<T>::~Vector()
{
	delete this->inputArr;
}

template<typename T>
int Vector<T>::getSize()
{
	return this->sizeArray;
}

template<typename T>
T& Vector<T>::operator[](int i) const
{
	return this->inputArr[i];
}

template<typename T>
Vector<T>& Vector<T>::operator++()
{
	this->incrementArr();

	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator--()
{
	this->decrementArr();

	return *this;
}

template<typename T>
Vector<T> Vector<T>::operator--(int)
{
	Vector<T> temp(*this);

	this->decrementArr();

	return temp;
}

template<typename T>
Vector<T> Vector<T>::operator++(int)
{
	Vector<T> temp(*this);

	this->incrementArr();

	return temp;
}


template<typename T>
inline void Vector<T>::incrementArr()
{
	for (size_t i = 0; i < sizeArray; i++)
	{
		++this->inputArr[i];
	}
}

template<typename T>
inline void Vector<T>::decrementArr()
{
	for (size_t i = 0; i < sizeArray; i++)
	{
		--this->inputArr[i];
	}
}
