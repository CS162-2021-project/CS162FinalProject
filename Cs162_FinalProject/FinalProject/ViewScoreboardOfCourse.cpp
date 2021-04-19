#include<string.h>
#include "Staff.h"
#include "Header.h"
#include<iostream>

using namespace std;

void ViewScoreboardOfCourse (Course *pCourse, char *courseID) {
    while (pCourse && pCourse->id != courseID) {
        pCourse = pCourse->courseNext;
    }
    if (pCourse && pCourse->id == courseID) {
        Scoreboard *pCur;
        pCur =pCourse->pScoreboard;
        while (pCur) {
            cout << pCur->stu.Name << "\t" << pCur->midterm <<  "\t" << pCur->final << "\t" << pCur->bonus << "\t" << pCur->total << endl;
            pCur = pCur->scoreboardNext;
        }
    }
}
