#include <bits/stdc++.h>
#include "Header.h"
#include "Course.h"
#include "Staff.h"

using namespace std;

int main() {
	//Input interfare

	Year* pYearHead = nullptr;
	int nYear = 0;
	int nClass = 0;
	int nSemester = 0;

	Course* pCourseHead = nullptr;	
	int nCourse = 0;

	while(1) {
		int respond = inputInterfare(); // Index of the task

		if (respond == 1) { // Create a year
			cout << "Please input the year: ";
			char *yearInput = new char[101]; cin >> yearInput;
			Create_New_Year(pYearHead, nYear, yearInput);
		}
			
		if (respond == 2) { // Create a class in a semester in a year
			cout << "Please input the year: ";
			char *yearInput = new char[101]; cin >> yearInput;
			cout << "Please input the semester: ";
			char *semesterInput = new char[101]; cin >> semesterInput;
			cout << "Please input the class name: ";
			char *className = new char[101]; cin >> className;
			createNewClass(pYearHead, nClass, semesterInput, yearInput, className);
		}

		if (respond == 6) { // Create a semester in a year
			cout << "Please input the year: ";
			char *yearInput = new char[101]; cin >> yearInput;
			cout << "Please input the semester: ";
			char *semesterInput = new char[101]; cin >> semesterInput;
			createNewSemester(pYearHead, nSemester, semesterInput, yearInput);
		}

		if (respond == 8) {
			cout << "Please input the year: ";
			char *yearInput = new char[101]; cin >> yearInput;
			cout << "Please input the semester: ";
			char *semesterInput = new char[101]; cin >> semesterInput;
			addNewCourse(pCourseHead, nCourse, semesterInput, yearInput);
		}

		if (respond == 10) {
			updateCourse(pCourseHead);			
		}

		if (respond == 11) {
			cout << "Please input the course ID you wish to delete: ";
			char *courseID = new char[101]; cin >> courseID;
			delete(pCourseHead, courseID);
		}

		if (respond == 0) { // End the program
			break;
		}
	}
}
