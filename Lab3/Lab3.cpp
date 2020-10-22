#include <iostream>
#include "Subtractor.h"
#include "Multiplier.h"

int main()
{
	double arr[]{ 0, 2, 3.5, -4 };

	Subtractor s;
	s.setOperands(arr, 4);

	s.logToScreen();

}

