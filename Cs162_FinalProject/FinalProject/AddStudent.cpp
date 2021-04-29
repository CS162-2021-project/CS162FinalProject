#include <iostream>
#include <fstream>
#include <string.h>
#include "Header.h"
#include "Class.h"

using namespace std;

void inputStudent(Student *&newStu) {
	cin.get();

	cout << "Input the student's ID: ";
	newStu -> studentID = new char[51];
	cin.getline(newStu -> studentID, 50);

	cout << "Input the student's name: ";
	newStu -> Name = new char[51];
	cin.getline(newStu -> Name, 50);

	cout << "Input the student's date of birth.\n";
	cout << "Year? ";
	cin >> newStu -> DOB.year;
	cout << "Month? ";
	cin >> newStu -> DOB.month;
	cout << "Day? ";
	cin >> newStu -> DOB.day;
	cin.get();

	cout << "Input the student's gender (type 0 if male, 1 if female): ";
	cin >> newStu -> gender;
	cin.get();
	system("cls");
}

void addStudent(Student*& pStudent, char* yearName, char* className, Student *& newStu, int add) {
	Student * cur = pStudent;
	while (cur != nullptr) {
		if  (strcmp(cur -> studentID, newStu -> studentID) == 0) {
			cout << "Failed to add a new student!!\n";
			cout << "The student you are about to add has already existed!!\n";
			system("pause");
			system("cls");
			return;
		}
		cur = cur -> studentNext;
	}
	char dirD[] = { "C:\\Github\\CS162FinalProject\\Data\\" };
	char d[505] = "";
	strcat(d, dirD);
	strcat(d, yearName);
	strcat(d, "\\");
	strcat(d, className);
	strcat(d, "\\");
	strcat(d, "Student.txt");

	ofstream fOut;                  	
	if (add)
		fOut.open(d);

    newStu -> sClass = className;
	newStu -> enrolledSession = new bool* [8];
	for (int i = 0; i < 7; i++) {
		newStu -> enrolledSession[i] = new bool[5];
		for (int j = 0; j < 4; j++)
			newStu -> enrolledSession[i][j] = false;
	}

	if (pStudent == nullptr) {
		pStudent = newStu;
		if (add)
			fOut << pStudent -> studentID << ',' << pStudent -> Name << ',' << pStudent -> DOB.year << "-" << pStudent -> DOB.month << "-" << pStudent -> DOB.day << ',' << pStudent -> gender << '\n';
	}
	else {
		Student* pCur = pStudent;
		while (pCur -> studentNext != nullptr) {
			pCur = pCur -> studentNext;
			if (add)
				fOut << pCur -> studentID << ',' << pCur -> Name << ',' << pCur -> DOB.year << "-" << pCur -> DOB.month << "-" << pCur -> DOB.day << ',' << pCur -> gender << '\n';
		}
		if (add)
			fOut << pCur -> studentID << ',' << pCur -> Name << ',' << pCur -> DOB.year << "-" << pCur -> DOB.month << "-" << pCur -> DOB.day << ',' << pCur -> gender << '\n';
		pCur -> studentNext = newStu;
		pCur = pCur -> studentNext;
		if (add)
			fOut << pCur -> studentID << ',' << pCur -> Name << ',' << pCur -> DOB.year << "-" << pCur -> DOB.month << "-" << pCur -> DOB.day << ',' << pCur -> gender << '\n';
	}
	if (add)
		fOut.close();
}