#include<iostream>
#include<string>
#include"Course.h"
#include"Header.h"
#include<direct.h>
#pragma warning(disable : 4996)

using namespace std;

void Create_New_Year(Year*& pHead, int& n, char* year) {
	ofstream fout;
	fout.open("C:\\GitHub\\CS162FinalProject\\Data\\year.txt");

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

	char dirD[] = "C:\\GitHub\\CS162FinalProject\\Data\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, year);
	_mkdir(c);
	
	strcat(c, "\\semester.txt");

	fout.open(c);
	fout << 0;
	fout.close();
}

void createNew_Class(Year*& pHead, int& n, char* semester, char* year, char* className)
{
	char dirD[] = "C:\\Github\\CCS162FinalProject\\Data\\";
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

	char d[500] = "";
	strcat(d, dirD);
	strcat(d, year);
	strcat(d, "\\");
	strcat(d, semester);
	strcat(d, "\\");
	strcat(d, className);
	_mkdir(c);

}
