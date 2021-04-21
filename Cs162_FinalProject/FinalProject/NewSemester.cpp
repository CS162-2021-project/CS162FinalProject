#include <bits/stdc++.h>
#include "Course.h"

using namespace std;

void createNewSemester(Semester*& pSemester, char* semesterName, char* yearName, int add) {
	char dirD[] = "C:\\Github\\CS162FinalProject\\Data\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, yearName);
	strcat(c, "\\Semester");
	strcat(c, "\\Semester.txt");

	ofstream fout;
	if (add)
		fout.open(c);

	Semester* cur = pSemester;
	if (pSemester == nullptr) {
		pSemester = new Semester;
		pSemester -> SemesterName = semesterName;
		if (add)
			fout << pSemester -> SemesterName;
	}
	else {
		while (cur -> semesterNext != nullptr) {
			if (add)
				fout << cur -> SemesterName << '\n';
			cur = cur -> semesterNext;
		}
		if (add)
			fout << cur -> SemesterName << '\n';
		cur -> semesterNext = new Semester;
		cur = cur -> semesterNext;
		cur -> SemesterName = semesterName;
		if (add)
			fout << cur -> SemesterName;
	}
	fout.close();

	char d[500] = "mkdir ";
	strcat(d, dirD);
	strcat(d, yearName);
	strcat(d, "\\Semester\\");
	strcat(d, semesterName);
	system(d);
}