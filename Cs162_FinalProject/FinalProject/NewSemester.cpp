#include <bits/stdc++.h>
#include "Course.h"

using namespace std;

void createNewSemester(Semester*& pSemester, char* semesterName, char* yearName) {
	char dirD[] = "C:\\Github\\CS162FinalProject\\Data\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, yearName);
	strcat(c, "\\semester.txt");

	ofstream fout;
	fout.open(c);

	Semester* cur = pSemester;
	if (pSemester == nullptr) {
		pSemester = new Semester;
		pSemester -> SemesterName = semesterName;
		fout << pSemester -> SemesterName;
	}
	else {
		while (cur -> semesterNext != nullptr) {
			fout << cur -> SemesterName << '\n';
			cur = cur -> semesterNext;
		}
		fout << cur -> SemesterName << '\n';
		cur -> semesterNext = new Semester;
		cur = cur -> semesterNext;
		cur -> SemesterName = semesterName;
		fout << cur -> SemesterName;
	}
	fout.close();

	char d[500] = "mkdir ";
	strcat(d, dirD);
	strcat(d, yearName);
	strcat(d, "\\");
	strcat(d, semesterName);
	system(d);
}