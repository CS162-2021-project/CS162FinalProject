#include <bits/stdc++.h>
#include "Header.h"
#include "Class.h"

using namespace std;

void inputStudent(Student *&newStu) {
	cout << "Input the student's ID: ";
	newStu -> studentID = new char[21];
	cin >> newStu -> studentID;

	cout << "Input the student's name: ";
	newStu -> Name = new char[21];
	cin >> newStu -> Name;

	cout << "Input the student's date of birth.\n";
	cout << "Year? ";
	cin >> newStu -> DOB.year;
	cout << "Month? ";
	cin >> newStu -> DOB.month;
	cout << "Day? ";
	cin >> newStu -> DOB.day;
	cin.get();

	cout << "Input the student's gender(type 1 if male, 0 if female): ";
	cin >> newStu -> gender;
	cin.get();
}

void addStudent(Student*& pStudent, char* yearName, char* className) {
	char dirD[] = { "C:\\Github\\CS162FinalProject\\Data\\" };
	char d[505] = "";
	strcat(d, dirD);
	strcat(d, yearName);
	strcat(d, "\\");
	strcat(d, className);
	strcat(d, "\\");
	strcat(d, "Student.txt");

	ofstream fOut(d);

	Student *newStu = new Student;
    inputStudent(newStu);

	if (pStudent == nullptr) {
		pStudent = newStu;
		pStudent -> studentNext = nullptr;
		fOut << pStudent -> studentID << ' ' << pStudent -> Name << ' ' << pStudent -> DOB.month << "-" << pStudent -> DOB.day << "-" << pStudent -> DOB.year << ' ' << pStudent -> gender;
	}
	else {
		Student* pCur = pStudent;
		while (pCur -> studentNext != nullptr) {
			pCur = pCur -> studentNext;
			fOut << pCur -> studentID << ' ' << pCur -> Name << ' ' << pCur -> DOB.month << "-" << pCur -> DOB.day << "-" << pCur -> DOB.year << ' ' << pCur -> gender;
		}
		pCur -> studentNext = newStu;
		pCur = pCur -> studentNext;
		pCur -> studentNext = nullptr;
		fOut << pCur -> studentID << ' ' << pCur -> Name << ' ' << pCur -> DOB.month << "-" << pCur -> DOB.day << "-" << pCur -> DOB.year << ' ' << pCur -> gender;
	}
	
}