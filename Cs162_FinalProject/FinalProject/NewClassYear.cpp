#include <bits/stdc++.h>
#include "Course.h"

using namespace std;

void createNewYear(Year*& pYear, char* yearName) {
	ofstream fout;
	fout.open("C:\\GitHub\\CS162FinalProject\\Data\\year.txt");

	Year* pCur = pYear;
	if (pYear == nullptr) {
		pYear = new Year;
		pYear -> YearName = yearName;
		pYear -> yearNext = nullptr;
		fout << pYear -> YearName;
	}
	else {
		while (pCur -> yearNext != nullptr) {
			fout << pCur -> YearName << endl;
			pCur = pCur -> yearNext;
		}
		pCur -> yearNext = new Year;
		pCur = pCur -> yearNext;
		pCur -> YearName = yearName;
		fout << pCur -> YearName;
		pCur -> yearNext = nullptr;
	}
	fout.close();

	char dirD[] = "C:\\GitHub\\CS162FinalProject\\Data\\";
	char c[500] = "mkdir ";
	strcat(c, dirD);
	strcat(c, yearName);
	system(c);
}