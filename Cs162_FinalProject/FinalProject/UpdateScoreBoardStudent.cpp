#include <iostream>
#include <fstream>
#include <string.h>
#include "Staff.h"
#include "Header.h"

using namespace std;

void updateScoreBoardStudent(Scoreboard *& pScr, char *yearName, char * semesterName, char *courseID, char* studentID) {
	Scoreboard * pCur = pScr;
	while(pCur != nullptr && strcmp(pCur->stu->studentID, studentID) != 0){
		pCur = pCur-> scoreboardNext;
	}	
	
	if(pCur != nullptr){
		cout << "Update Score of student " << studentID << ": " << endl;
		cout << "Midterm's mark: "; cin >> pCur->midterm;
		cout << "Final's mark: "; cin >> pCur->final;
		cout << "Bonus's mark: "; cin >> pCur->bonus;
		cout << "Total's mark: "; cin >> pCur->total;
		cout << "Update successfully!!\n";
	} else {
		cout << "Student ID not found." << '\n';
	}
	system("pause");
	system("cls");

	char dirOut[] = { "C:\\Github\\CS162FinalProject\\Data\\" };
	char ddd[505] = "";
	strcat(ddd, dirOut);
	strcat(ddd, yearName);
	strcat(ddd, "\\Semester\\");
	strcat(ddd, semesterName);
	strcat(ddd, "\\");
	strcat(ddd, courseID);
	strcat(ddd, "\\");
	strcat(ddd, "Scoreboard.txt");

	ofstream fOut(ddd);

	pCur = pScr;
	int cnt = 0;
	while (pCur != nullptr) {
		fOut << ++cnt << ',' << pCur -> stu -> studentID << ',' << pCur -> stu -> Name << ',' << pCur -> midterm << ',' << pCur -> final << ',' << pCur -> bonus << ',' << pCur -> total << '\n';
		pCur = pCur -> scoreboardNext;
	}
	fOut.close();
}


