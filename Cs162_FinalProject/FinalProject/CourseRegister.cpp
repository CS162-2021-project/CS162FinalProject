#include <iostream>
#include <string.h>
#include "Course.h"
#include "Header.h"

using namespace std;

void courseRegistration(Semester *& pSemester) {
	if (pSemester -> startReg.year != -1) {
		while(true) {
			cout << "WARNING!! There's already a course registration session in this semester.\n"; 
			cout << "The registration session for this semester is from " << pSemester -> startReg.year << '/' << pSemester -> startReg.month << '/' << pSemester -> startReg.day << " to "
			<< pSemester -> endReg.year << '/' << pSemester -> endReg.month << '/' << pSemester -> endReg.day << '\n';
			cout << "Do you want to overwrite it?\n";
			cout << "1: Yes\n";
			cout << "0: No\n";
			
			cout << "Your input: ";
			char *respond = new char[101]; cin >> respond;
			system("cls");
			if (strlen(respond) > 1 || (respond[0] < '0' || '9' < respond[0])) {
				cout << "Invalid, please try again\n\n";
				continue;
			}
			system("cls");
			if (respond[0] - '0' == 0) return;
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
}