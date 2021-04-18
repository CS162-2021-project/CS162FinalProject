#include <bits/stdc++.h>
#include "Header.h"
#include "Class.h"
#include "Course.h"
#include "Staff.h"
#include "Student.h"
#include "System.h"

using namespace std;

int main() {
	//Input interface

	Year* pYear = nullptr;
	cout << "Welcome to the HCMUS Course Registration system\n\n";
	while(true) {
		int respondRole = chooseRole();
		if (respondRole == 0) break;
		else if (respondRole == 1) {
			if (LogIn(1)) { // Login as a Staff
				int respondYear = yearScreen();

			}
		}
		else if (respondRole == 2) {
			if (LogIn(2)) { // Login as a Student
			}
		}
		else
			cout << "Invalid, please try again\n\n";
	}
			
   	/*
   	int respond = inputInterfare(); // Index of the task

   	if (respond == 1) { // Create a year
   		cout << "Please input the year: ";
   		char *yearName = new char[21]; cin >> yearName;
   		createNewYear(pYear, yearName);
   		cout << "Done creating year\n\n";

   		delete []yearInput;
   	}
   		
   	if (respond == 2) { // Create a class in a semester in a year
   		cout << "Please input the year: ";
   		char *yearName = new char[21]; cin >> yearName;
   		cout << "Please input the class name: ";
   		char *className = new char[21]; cin >> className;

   		Year* curYear = pYear;
   		while (cur != nullptr && cur -> YearName != yearName)
   			curYear = curYear -> yearNext;
   		if (cur == nullptr) 
   			cout << "The year you input is not in the data, please create the year first!!";
   		else	
   			createNewClass(pYear -> pClass, yearName, className);
   		cout << "Done creating class\n\n";

   		delete []yearInput;
   		delete []className;
   	}

		if (respond == 3) { // Add new students to first-year classes
   	}

   	if (respond == 4) {
   		cout << "Please put the .csv file you wish to import into the folder Data\\File_csv and input the name of that file: ";
   		char *studentCSV = new char[51];
   		cin >> studentCSV;
   	}

   	if (respond == 6) { // Create a semester in a year
   		cout << "Please input the year: ";
   		char *yearInput = new char[21]; cin >> yearInput;
   		cout << "Please input the semester: ";
   		char *semesterInput = new char[21]; cin >> semesterInput;

   		Year* curYear = pYear;
   		while (cur != nullptr && cur -> YearName != yearName)
   			curYear = curYear -> yearNext;
   		if (cur == nullptr) 
   			cout << "The year you input is not in the data, please create the year first!!";
   		else
   			createNewSemester(pYear -> pSemester, semesterInput, yearInput);
   		cout << "Done creating semester\n\n";

   		delete []yearInput;
   		delete []semesterInput;
   	}

   	if (respond == 8) {
   		cout << "Please input the year: ";
   		char *yearInput = new char[21]; cin >> yearInput;
   		cout << "Please input the semester: ";
   		char *semesterInput = new char[21]; cin >> semesterInput;
   		addNewCourse(pCourse, semesterInput, yearInput);
   		cout << "Done adding course\n\n";

   		delete []yearInput;
   		delete []semesterInput;
   	}

   	if (respond == 9) {
   	}

   	if (respond == 10) {
   		updateCourse(pCourseHead);			
   		cout << "Done updating course\n\n";
   	}

   	if (respond == 11) {
   		cout << "Please input the course ID you wish to delete: ";
   		char *courseID = new char[21]; cin >> courseID;
   		cout << "Done deleting course\n\n"; 
   		delete(pCourse, courseID);
   		delete []courseID;
   	}

   	if (respond == 0) { // End the program
   		break;
   	}
   	*/
}
