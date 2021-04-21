#include <iostream>
#include <fstream>
#include <string.h>
#include "Course.h"

using namespace std;

void createNewYear(Year*& pYear, char* yearName, int add) {
	ofstream fout;
	if (add)
		fout.open("C:\\GitHub\\CS162FinalProject\\Data\\Year.txt");

	Year* pCur = pYear;
	while (pCur != nullptr) {
		if (pCur -> YearName == yearName) {
			cout << "The year you are about to create has already existed\n";
			return;
		}
		pCur = pCur -> yearNext;
	}

	pCur = pYear;
	if (pYear == nullptr) {
		pYear = new Year;
		pYear -> YearName = yearName;
		if (add)
			fout << pYear -> YearName;
	}
	else {
		while (pCur -> yearNext != nullptr) {
			if (add)
				fout << pCur -> YearName << '\n';
			pCur = pCur -> yearNext;
		}
		if (add)
			fout << pCur -> YearName << '\n';
		pCur -> yearNext = new Year;
		pCur = pCur -> yearNext;
		pCur -> YearName = yearName;
		if (add)
			fout << pCur -> YearName;
	}
	if (add)
		fout.close();

	char dirD[] = "C:\\GitHub\\CS162FinalProject\\Data\\";
	char c[500] = "mkdir ";
	strcat(c, dirD);
	strcat(c, yearName);
	system(c);
}