#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "TodoCont.h"
#include <windows.h>
using namespace std;

Mainpart Ms;
int main()
{
	char choose = '0';
	for(;;)
	{
		cout << "Hello in your To do fille reader" << endl;
		cout << "What you wanna do? (1. Create new Todo Task, 2. Show your task list, 3. finish some task, 4 exit): ";
		cin>>choose; cout << endl;
		switch (choose)
		{
		case '1':
		{
			Ms.CreatingTask();
			break;
		}

		case '2':
		{
			Ms.ShowingTaskList();
			break;
		}

		case '3':
		{
			//Ms.FinishingTask();
			break;
		}

		case '4':
		{
			exit(0);
			break;
		}

		default:
		{
			cout << "Try again and write: \h 1. Create a new Plan \h 2. See your plans \h 3. finish a plan \h 4. to exit program" << endl;
			break;
		}
		}

		system("pause");
		system("cls");
		if(choose =='4') exit(0);
	}
}
