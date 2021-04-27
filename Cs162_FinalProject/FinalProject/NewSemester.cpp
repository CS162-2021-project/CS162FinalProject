#include <iostream>
#include <fstream>
#include <string.h>
#include "Course.h"

using namespace std;

void createNewSemester(Semester*& pSemester, char* semesterName, char* yearName, Date startDate, Date endDate, int add) {
	Semester* cur = pSemester;

	while (cur != nullptr) {
		if (strcmp(cur -> SemesterName, semesterName) == 0) {
			cout << "Failed to create a new semester!!\n";
			cout << "The semester you are about to create has already existed!!\n";
			system("pause");
			system("cls");
			return;
		}
		cur = cur -> semesterNext;
	}

	char dirD[] = "C:\\Github\\CS162FinalProject\\Data\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, yearName);
	strcat(c, "\\Semester");
	strcat(c, "\\Semester.txt");

	ofstream fOut;
	if (add)
		fOut.open(c);

	cur = pSemester;

	if (pSemester == nullptr) {
		pSemester = new Semester;
		pSemester -> SemesterName = semesterName;
		pSemester -> startDate = startDate;
		pSemester -> endDate = endDate;
	}
	else {
		while (cur -> semesterNext != nullptr) {
			cur = cur -> semesterNext;
		}

		cur -> semesterNext = new Semester;
		cur = cur -> semesterNext;
		cur -> SemesterName = semesterName;
		cur -> startDate = startDate;
		cur -> endDate = endDate;
	}

	if (add) {
		cur = pSemester;
		while (cur != nullptr) {
			fOut << cur -> SemesterName << ' ';
			fOut << cur -> startDate.year << ' ' << cur -> startDate.month << ' ' << cur -> startDate.day << ' ';
			fOut << cur -> endDate.year << ' ' << cur -> endDate.month << ' ' << cur -> endDate.day << ' ';
			fOut << cur -> startReg.year << ' ' << cur -> startReg.month << ' ' << cur -> startReg.day << ' ';
			fOut << cur -> endReg.year << ' ' << cur -> endReg.month << ' ' << cur -> endReg.day << '\n';
			cur = cur -> semesterNext;
		}
		fOut.close();
	}

	char d[500] = "";
	strcat(d, "mkdir ");
	strcat(d, dirD);
	strcat(d, yearName);
	strcat(d, "\\Semester\\");
	strcat(d, semesterName);
	system(d);
}