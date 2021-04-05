#include <bits/stdc++.h>
#include "Header.h"
#include "Course.h"
#include "Staff.h"

using namespace std;

int main() {
	//Input interfare

	while(1) {
		int respond = inputInterfare(); // Index of the task
		
		Year* pHead = nullptr;

		int nYear = 0;
		if (respond == 1) { // Create a year
			cout << "Please input the year: ";
			char *yearInput = new char[101]; cin >> yearInput;
			Create_New_Year(pHead, nYear, yearInput);
		}
			
		int nClass = 0;
		if (respond == 2) { // Create a class in a semester in a year
			cout << "Please input the year: ";
			char *yearInput = new char[101]; cin >> yearInput;
			cout << "Please input the semester: ";
			char *semesterInput = new char[101]; cin >> semesterInput;
			cout << "Please input the class name: ";
			char *className = new char[101]; cin >> className;
			createNewClass(pHead, nClass, semesterInput, yearInput, className);
		}

		int nSemester = 0;
		if (respond == 6) { // Create a semester in a year
			cout << "Please input the year: ";
			char *yearInput = new char[101]; cin >> yearInput;
			cout << "Please input the semester: ";
			char *semesterInput = new char[101]; cin >> semesterInput;
			createNewSemester(pHead, nSemester, semesterInput, yearInput);
		}

		if (respond == 0) { // End the program
			break;
		}
	}
}
