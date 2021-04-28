#include "Student.h"
#include "Header.h"
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;


void viewScoreBoard(Course* pCourse, char* studentID) {
	cout << setw(15) << left << "Course";
	cout << setw(20) << left << "Midterm's Mark";
	cout << setw(20) << left << "Final's Mark";
	cout << setw(20) << left << "Bonus's Mark";
	cout << setw(20) << left << "Total's Mark" << '\n';
	cout << '\n';

	while (pCourse != nullptr) {
		Scoreboard *pCur = pCourse -> pScoreboard; 
		while (pCur != nullptr) {
			if (strcmp(pCur -> stu -> studentID, studentID) == 0) {
				cout << setw(15) << left << pCourse -> id;
				cout << setw(20) << left << pCur -> midterm;
				cout << setw(20) << left << pCur -> final;
				cout << setw(20) << left << pCur -> bonus;
				cout << setw(20) << left << pCur -> total << '\n';
				break;
			}
			pCur = pCur -> scoreboardNext;
		}
		pCourse = pCourse -> courseNext;
	}

	system("pause");
	system("cls");
}
