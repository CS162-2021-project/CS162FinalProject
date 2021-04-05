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

void createNewClass(Year*& pHead, int& n, char* semester, char* year, char* className)
{
	char dirD[] = "C:\\Github\\CS162FinalProject\\Data\\";
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

void addNewCourse(Course*& pHead, int& n, char* semester, char* year) {
	char dirD[] = "C:\\Github\\CS162FinalProject\\Data\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, year);
	strcat(c, "\\");
	strcat(c, semester);
	strcat(c, "\\course.txt");

	//

	ofstream fout;
	fout.open(c);
	if (fout.is_open()) {
		n += 1;
		fout << n << endl;
		Course* pCur = pHead;
		if (!pHead) {
			pHead = new Course;
			pCur = pHead;
		}
		else {
			while (pCur->next) {
				pCur = pCur->next;
			}
			pCur->next = new Course;
			pCur = pCur->next;
		}
		// get info
		cin.ignore(1001, '\n');
		cin.get(pCur->id, 101, '\n');
		fout << pCur->id << endl;

		cin.ignore(1001, '\n');
		cin.get(pCur->name, 101, '\n');
		fout << pCur->name << endl;

		cin.ignore(1001, '\n');
		cin.get(pCur->lecturerName, 101, '\n');
		fout << pCur->lecturerName << endl;

		cin >> pCur->numberOfCredits;
		fout << pCur->numberOfCredits << endl;
		cin >> pCur->maxStudent;
		fout << pCur->numberOfCredits << endl;

		cout << " the session that the course will be performed (MON / TUE / WED / THU / FRI / SAT)" << endl;
		cout << " and shift S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30))" << endl;
		cout << "Please input 2 sesstions :" << endl;
		cin >> pCur->date.d1 >> pCur->date.s1;
		cin >> pCur->date.d2 >> pCur->date.s2;
		fout << pCur->date.d1 << ' ' << pCur->date.s1 << endl;
		fout << pCur->date.d2 << ' ' << pCur->date.s2 << endl;
	}
	fout.close();
}
