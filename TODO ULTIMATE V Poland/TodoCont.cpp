
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
    int LineOfTask = 0;
    fstream Tasklist;
    Tasklist.close(); // It was usefull while I was working on this code, so I will leave it here;
    Tasklist.open("Xul.txt", ios::in | ios::app);

    while (getline(Tasklist, line)) { SizeOfTable++; }
    string* xdon = new string[SizeOfTable];
    //Tasklist.clear();
    //Tasklist.seekg(0); // This part is reseting pointer on file to 0, allowing to use get line one more time;

    Tasklist.close(); // It was usefull while I was working on this code, so I will leave it here;
    Tasklist.open("Xul.txt", ios::in | ios::app);

    while (getline(Tasklist, line))
    {
        xdon[FirstForint] = line;
        switch (LineOfTask)
        {
        case 0: {cout << "| Done: | " << xdon[FirstForint] << " "; break; }
        case 1: {cout << "| Priority: | " << xdon[FirstForint] << " "; break; }
        case 2: {cout << "| Done: | " << xdon[FirstForint] << " |" << endl; break; }
        default: {cout << "Welp, thats some error :D"; break; }
        }

        FirstForint++; LineOfTask++;
        if (LineOfTask >= 3) LineOfTask = 0;
    }

    Tasklist.close();
    delete[] xdon;
}

/*-_-_-_-_-_-_-_-_- Finishing Task -_-_-_-_-_-_-_-_-*/
//void Mainpart::FinishingTask()
//{int fin;
//int lineno = 1; int colno = 0;
//string don[25];
//string prio[25];
//string text[25];
//fstream Xul;
//Xul.open("Xul.txt", ios::out | ios::app);
//while (getline(Xul, line))
//{
//    switch (lineno)
//    {
//    case 1: don[colno] = line; break;
//    case 2: prio[colno] = line; break;
//    case 3: text[colno] = line; break;
//    }
//    if (lineno == 3)
//    {
//        lineno = 0;
//        colno++;
//        lineno++;
//    }
//    Xul.close();
//    int i;
//    for (i = 0; i < colno; i++)
//    {
//        int nah = i + 1;
//        cout << "| Done: " << don[i] << " | " << nah << ". | Priority: " << prio[i] << " | " << " | Text: " << text[i] << " | " << endl << endl;
//    }
//
//    cout << "What task you finish? "; cin >> fin; cout << endl;
//    if (fin <= i)
//    {
//        int NAR = fin - 1;
//        {
//            cout << "| " << fin << ". | Priority: " << prio[i] << " | " << " | Text: " << text[i] << " | " << endl;
//            cout << "It is this Task you finish? (1.Yes / 2.No) "; int yes; cin >> yes;
//
//            switch (yes)
//            {
//            case 1:
//            {
//                don[NAR] = true;
//                cout << "| " << don[NAR] << " | " << fin << ". | Priority: " << prio[i] << " | " << " | Text: " << text[i] << " | " << endl;
//                MP.SavingTaskList();
//                break;
//            }
//            case 2: exit(0); break;
//            default: cout << "Wybierz '1' aby potwierdzic lub '2' aby wybrac ponownie"; break;
//            }
//        }
//
//
//    }
//    Xul.close();
//}
//   delete[] text;
//   delete[] prio;
//   delete[] don;
//}

