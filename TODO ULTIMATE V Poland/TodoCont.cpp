
#include "TodoCont.h"

using namespace std;
Mainpart MP;

/*-_-_-_-_-_-_-_-_- Creating Task -_-_-_-_-_-_-_-_-*/
void Mainpart::CreatingTask()
{ 
MP.isdone = false;
cout << "how important is this task? ";
cin >> MP.priority; cout << endl;

cout << "What you must to do? ";
cin >> MP.task; cout << endl;

MP.SavingTaskList();
}
/*-_-_-_-_-_-_-_-_- Saving Task List -_-_-_-_-_-_-_-_-*/

void Mainpart::SavingTaskList()
{
fstream Xul;
Xul.close();
Xul.open("Xul.txt", ios::out | ios::app);

    Xul<< isdone << endl;
    Xul<< priority << endl;
    Xul<< task << endl;
    Xul.close();
}

/*-_-_-_-_-_-_-_-_- Showing Task List -_-_-_-_-_-_-_-_-*/
void Mainpart::ShowingTaskList()
{
    int SizeOfTable = 0;
    int FirstForint = 0; 
    int LineOfTask = 0; // used in switch in line 53
    char yes; // used to define answer in line 116
    fstream Tasklist;
    Tasklist.close(); // It was usefull while I was working on this code, so I will leave it here;
    Tasklist.open("Xul.txt", ios::in | ios::app);

    while (getline(Tasklist, line)) { SizeOfTable++; }
    string* xdon = new string[SizeOfTable];

    Tasklist.clear();
    Tasklist.seekg(0); // This part is reseting pointer on file to 0, allowing to use getline one more time;

    while (getline(Tasklist, line))
    {
        xdon[FirstForint] = line;
        switch (LineOfTask)
        {
        case 0: {
            cout << (FirstForint/3)+1 << ". \t| Is done: | ";
            if (xdon[FirstForint] == "0") { cout << "No"; }
            else cout << "Yes";
            cout << " "; break; }
        case 1: {cout << "| Priority: | " << xdon[FirstForint] << " "; break; }
        case 2: {cout << "| Task: | " << xdon[FirstForint] << " |" << endl; break; }
        default: {cout << "Welp, that's some error :D"; break; }
        }

        FirstForint++; LineOfTask++;
        if (LineOfTask >= 3) LineOfTask = 0;
    }

    delete[] xdon;
}

/*-_-_-_-_-_-_-_-_- Finishing Task -_-_-_-_-_-_-_-_-*/
void Mainpart::FinishingTask()
{
    int withToFinish = 0;
    int SizeOfTable = 0;
    int FirstForint = 0;// used in switch in line 53
    int show = 0;
    char yes;
    int LineOfTask = 0;

    fstream Tasklist;
    Tasklist.close();
    Tasklist.open("Xul.txt", ios::in | ios::app);

    while (getline(Tasklist, line)) { SizeOfTable++; }
    string* xdon = new string[SizeOfTable];

    Tasklist.close(); // It was usefull while I was working on this code, so I will leave it here;
    Tasklist.open("Xul.txt", ios::in | ios::app);
    Start:
    while (getline(Tasklist, line))
    {
        xdon[FirstForint] = line;
        switch (LineOfTask)
        {
        case 0: {
            cout << (FirstForint / 3) + 1 << ". \t| Is done: | ";
            if (xdon[FirstForint] == "0") { cout << "No"; }
            else cout << "Yes";
            cout << " "; break; }
        case 1: {cout << "| Priority: | " << xdon[FirstForint] << " "; break; }
        case 2: {cout << "| Task: | " << xdon[FirstForint] << " |" << endl; break; }
        default: {cout << "Welp, that's some error :D"; break; }
        }

        FirstForint++; LineOfTask++;
        if (LineOfTask >= 3) LineOfTask = 0;
    }

    cout << "What task you finish? "; cin >> show; withToFinish=(show-1)*3; cout << endl;
    if (withToFinish <= SizeOfTable)
    {
        {   ERR0: // Used when user put wrong char in line 116 -> case: Default;
            cout << "| " << show << ". | Priority: " << xdon[withToFinish+1] << " | " << " | Text: " << xdon[withToFinish+2] << " | " << endl;
            cout << "Is it Task that you want to finish? (1.Yes / 2.No) "; 
            cin >> yes;

            switch (yes)
            {
            case '1':
            {
                xdon[withToFinish] = true;
                cout << "| " << show << ". | Priority: " << xdon[withToFinish + 1] << " | " << " | Text: " << xdon[withToFinish + 2] << " | " << endl;
                MP.SavingTaskList();
                break;
            }
            case '2': goto Start; break;
            default: cout << "Choose '1' to confirm or '2' for different task"; goto ERR0; break;
            }
        }


    }
    Tasklist.close();
    delete[] xdon;
}


