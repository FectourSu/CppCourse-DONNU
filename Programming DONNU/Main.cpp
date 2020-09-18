#include <iostream>
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"

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

			Task1 firstTask;
			firstTask.Run();
		}
		else if (userSelect == 2)
		{
			system("cls");

			Task2 secondTask;
			secondTask.Run();
		}
		else if (userSelect == 3)
		{
			system("cls");

			Task3 threeTask;
			threeTask.Run();

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
