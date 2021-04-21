#include"Student.h"
#include"Header.h"
#include<iostream>
using namespace std;

void viewScoreBoard(Course* pCourse, char* studentID) {
	while (pCourse) {
		while (pCourse->pScoreboard) {
			if (strcmp(pCourse->pScoreboard->stu.studentID, studentID) == 0) {
				cout << "Final score :";
				cout << pCourse->pScoreboard->final << endl;
				cout << "Midterm score :";
				cout << pCourse->pScoreboard->midterm << endl;
				cout << "Bonus :";
				cout << pCourse->pScoreboard->bonus;
				cout << "Total score :";
				cout << pCourse->pScoreboard->total << endl;
				return;
			}
			pCourse->pScoreboard = pCourse->pScoreboard->scoreboardNext;
		}
		pCourse = pCourse->courseNext;
	}
}