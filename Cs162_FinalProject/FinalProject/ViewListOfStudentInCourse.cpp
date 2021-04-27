#include <iostream>
#include <iomanip>
#include <string.h>
#include "Staff.h"
#include "Header.h"

using namespace std;

void viewListOfStudentsInCourse (Student *pStudent, char *courseID) {
	while (1) {
		Student *pStuInCourse = pStudent;
	    while (pStuInCourse) {
	        cout << setw(12) << left << pStuInCourse->studentID;
	        cout << setw(30) << left << pStuInCourse->Name;
	        cout << setw(10) << left << pStuInCourse->sClass;
	        cout << setw(8) << left << ((pStuInCourse->gender) ? "FEMALE" : "MALE");
	        cout << pStuInCourse->DOB.day << "/" << pStuInCourse->DOB.month << "/" << pStuInCourse->DOB.year << '\n';
	        pStuInCourse = pStuInCourse -> studentNext;
    	}
    	cout << '\n';

    	cout << "Do you want to export the list of students to a CSV file?\n";
    	cout << "0: No\n";
    	cout << "1: Yes\n\n";

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 1 || (respond[0] < '0' || '1' < respond[0])) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		if (respond[0] - '0')
			exportStudentToCsv(pStudent, courseID);
		return;
	}
}
