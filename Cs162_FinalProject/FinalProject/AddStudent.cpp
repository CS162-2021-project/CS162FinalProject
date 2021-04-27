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
   			while (true) {
   				cout << "A student with the same ID has already existed in this class\n";
   				cout << "Do you want to replace him/her?\n";
   				cout << "0: No\n";
   				cout << "1: Yes\n";

				cout << "Your input: ";
				char *respond = new char[101]; cin >> respond;
				system("cls");
				if (strlen(respond) > 1 || (respond[0] < '0' || '9' < respond[0])) {
					cout << "Invalid, please try again\n\n";
					continue;
				}
				if (respond[0] - '0' == 0) return;
				else break;
   			}
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