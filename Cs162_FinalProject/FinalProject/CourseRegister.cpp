#include <iostream>
#include <fstream>
#include <string.h>
#include "Course.h"
#include "Header.h"

using namespace std;

void courseRegistration(Semester *& pSemester, Semester * totSemester, char * yearName) {
	if (pSemester -> startReg.year != -1) {
		while(true) {
			cout << "WARNING!! There's already a course registration session in this semester.\n"; 
			cout << "The registration session for this semester is from " << pSemester -> startReg.year << '/' << pSemester -> startReg.month << '/' << pSemester -> startReg.day << " to "
			<< pSemester -> endReg.year << '/' << pSemester -> endReg.month << '/' << pSemester -> endReg.day << "\n\n";
			cout << "Do you want to overwrite it?\n";
			cout << "1: Yes\n";
			cout << "0: No\n";
			
			cout << "Your input: ";
			char *respond = new char[101]; cin >> respond;
			system("cls");
			if (strlen(respond) > 1 || (respond[0] < '0' || '1' < respond[0])) {
				cout << "Invalid, please try again\n\n";
				continue;
			}
			system("cls");
			int x = respond[0] - '0';
			delete[] respond;
			if (x == 0) return;
			else break;
		}
	}
	 
	cout << "Please input the start date of the registration session: \n";
	cout << "Year: "; cin >> pSemester -> startReg.year;
	cout << "Month: "; cin >> pSemester -> startReg.month;
	cout << "Day: "; cin >> pSemester -> startReg.day;
	cout << "Please input the end date of the registration session: \n";	
	cout << "Year: "; cin >> pSemester -> endReg.year;
	cout << "Month: "; cin >> pSemester -> endReg.month;
	cout << "Day: "; cin >> pSemester -> endReg.day;
	cout << "Finish, The registration session for this semester is from " << pSemester -> startReg.year << '/' << pSemester -> startReg.month << '/' << pSemester -> startReg.day << " to "
			<< pSemester -> endReg.year << '/' << pSemester -> endReg.month << '/' << pSemester -> endReg.day << '\n';
	system("pause");
	system("cls");

	char dirD[] = "C:\\Github\\CS162FinalProject\\Data\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, yearName);
	strcat(c, "\\Semester");
	strcat(c, "\\Semester.txt");

	ofstream fOut(c);

	Semester * cur = totSemester;
	while (cur != nullptr) {
		fOut << cur -> SemesterName << ' ';
		fOut << cur -> startDate.year << ' ' << cur -> startDate.month << ' ' << cur -> startDate.day << ' ';
		fOut << cur -> endDate.year << ' ' << cur -> endDate.month << ' ' << cur -> endDate.day << ' ';
		fOut << cur -> startReg.year << ' ' << cur -> startReg.month << ' ' << cur -> startReg.day << ' ';
		fOut << cur -> endReg.year << ' ' << cur -> endReg.month << ' ' << cur -> endReg.day << '\n';
		cur = cur -> semesterNext;
	}
	fOut.close();
}