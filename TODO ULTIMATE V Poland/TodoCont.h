#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#ifndef TodoCont_h
#define TodoCont_h

using namespace std;

class Mainpart
{
private:
int ID;
bool isdone; //allowing to check if Task is done or not;
string priority; //Allowing to sort taks by pririty (do to later);
string task; //Body of Tasks in file;
string line; //Body of task in memory;
void SavingTaskList(); //Subfunction that saving changes in task file;
public:
//Mainpart(int = 0, bool = false, string = "Null", string = "Missing", string="Missing"); // There is a issue that I cant fix UwU
void CreatingTask(); //Creating new record in memory with task;
int ShowingTaskList(); //Printing a list of task from file; For the sake of Finish it's also returning size of table;,
void FinishingTask(); //Function that allowing to finish task, and to delete it from file;
};


#endif 
