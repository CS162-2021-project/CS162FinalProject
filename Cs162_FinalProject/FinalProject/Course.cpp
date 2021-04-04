#include<iostream>
#include<string>
#include"Course.h"
#include"Header.h"

using namespace std;

void Create_New_Year(Year*& pHead, int& n, char* year) {
	ofstream fout;
	fout.open("C:\\GitHub\\CS162FinalProject\\Cs162_FinalProject\\Data\\year.txt");

	Year* pCur = pHead;
	n += 1;
	fout << n << endl;
	if (pHead == nullptr) {
		pHead = new Year;
		pHead->years = year;
		pHead->pNext = nullptr;
		fout << pHead->years;
	}
	else {
		while (pCur != nullptr) {
			fout << pCur->years << endl;
			pCur = pCur->pNext;
		}
		pCur = new Year;
		pCur->years = year;
		fout << pCur->years;
		pCur->pNext = nullptr;
	}
	fout.close();

	char dirD[] = "C:\\GitHub\\CS162FinalProject\\Cs162_FinalProject\\Data\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, year);
	//CreateDirectoryA(c, NULL);
	strcat(c, "\\semester.txt");

	fout.open(c);
	fout << 0;
	fout.close();
}