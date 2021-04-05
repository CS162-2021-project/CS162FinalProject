#include <bits/stdc++.h>
#include "Course.h"
#include "Header.h"

using namespace std;

void Create_New_Year(Year*& pHead, int& n, char* year) {
	ofstream fout;
	fout.open("E:\\GitHub\\CS162FinalProject\\Data\\year.txt");

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

	char dirD[] = "E:\\GitHub\\CS162FinalProject\\Data\\";
	char c[500] = "mkdir ";
	strcat(c, dirD);
	strcat(c, year);
	system(c);
	
	strcat(c, "\\semester.txt");

	fout.open(c);
	fout << 0;
	fout.close();
}

void createNewSemester(Year*& pHead, int& n, char* semester, char* year)
{
	char dirD[] = "E:\\Github\\CS162FinalProject\\Data\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, year);
	strcat(c, "\\semester.txt");

	ofstream fout;
	fout.open(c);

	Year* cur = pHead;
	n += 1;
	fout << n << endl;
	if (pHead == nullptr) {
		pHead = new Year;
		pHead->semesters = semester;
		pHead->pNext = nullptr;
		fout << pHead->semesters;
	}
	else {
		while (cur != nullptr) {
			fout << cur->semesters << endl;
			cur = cur->pNext;
		}
		cur = new Year;
		cur->semesters = semester;
		fout << cur->semesters;
		cur->pNext = nullptr;
	}
	fout.close();

	char d[500] = "mkdir ";
	strcat(d, dirD);
	strcat(d, year);
	strcat(d, "\\");
	strcat(d, semester);
	system(d);

	strcat(d, "\\class.txt");
	fout.open(d);
	fout << 0;
	fout.close();
}

void createNewClass(Year*& pHead, int& n, char* semester, char* year, char* className)
{
	char dirD[] = "E:\\Github\\CCS162FinalProject\\Data\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, year);
	strcat(c, "\\");
	strcat(c, semester);
	strcat(c, "\\class.txt");

	ofstream fout;
	fout.open(c);

	Year* cur = pHead;
	n += 1;
	fout << n << endl;

	if (pHead == nullptr) {
		pHead = new Year;
		pHead->className = className;
		pHead->pNext = nullptr;
		fout << pHead->className;
	}
	else {
		while (cur != nullptr) {
			fout << cur->className << endl;
			cur = cur->pNext;
		}
		cur = new Year;
		cur->className = className;
		fout << cur->className;
		cur->pNext = nullptr;
	}
	fout.close();

	char d[500] = "mkdir ";
	strcat(d, dirD);
	strcat(d, year);
	strcat(d, "\\");
	strcat(d, semester);
	strcat(d, "\\");
	strcat(d, className);
	system(d);
}
