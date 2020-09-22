#include <iostream>
#include "Vector.h"
int main()
{
	int size = 10;

	Vector<int> myVector(size);

    std::cout << myVector.getSize() << std::endl;

	for (size_t i = 0; i < size; i++)
	{
		myVector[i] = i;
	}

	for (size_t i = 0; i < size; i++)
	{
		std::cout << myVector[i] << " ";
	}

	std::cout << std::endl;

	auto copyVector = myVector--;

	std::cout << "Post-increment array : ";

	for (size_t i = 0; i < size; i++)
	{
		std::cout << copyVector[i] << " ";
	}

	std::cout << std::endl;
}
