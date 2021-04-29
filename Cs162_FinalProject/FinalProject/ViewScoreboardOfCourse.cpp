#include "Staff.h"
#include "Header.h"
#include <iostream>
#include <iomanip>
#include <string.h>


using namespace std;

void viewScoreboardOfCourse (Course *curCourse) {
    Scoreboard *pCur;
    pCur = curCourse -> pScoreboard;
    cout << setw(30) << left << "Name";
    cout << setw(20) << left << "ID";
    cout << setw(20) << left << "Midterm's Mark";
    cout << setw(20) << left << "Final's Mark";
    cout << setw(20) << left << "Bonus's Mark";
    cout << setw(20) << left << "Total's Mark" << '\n';
    cout << '\n';

    while (pCur) {
        cout << setw(30) << left << pCur->stu->Name;
        cout << setw(20) << left << pCur->stu->studentID;
        cout << setw(20) << left << pCur->midterm;
        cout << setw(20) << left << pCur->final;
        cout << setw(20) << left << pCur->bonus;
        cout << setw(20) << left << pCur->total << '\n';
        pCur = pCur->scoreboardNext;
    }
}
