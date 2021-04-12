#include <bits/stdc++.h>
#include "Header.h"
#include "Course.h"
#include "Staff.h"

using namespace std;

int main() {
	//Input interfare

	Year* pYear = nullptr;

	while(1) {
		int respond = inputInterfare(); // Index of the task

		if (respond == 1) { // Create a year
			cout << "Please input the year: ";
			char *yearInput = new char[21]; cin >> yearInput;
			Create_New_Year(pYearHead, yearInput);
			cout << "Done creating year\n\n";

			delete []yearInput;
		}
			
		if (respond == 2) { // Create a class in a semester in a year
			cout << "Please input the year: ";
			char *yearInput = new char[21]; cin >> yearInput;
			cout << "Please input the semester: ";
			char *semesterInput = new char[21]; cin >> semesterInput;
			cout << "Please input the class name: ";
			char *className = new char[21]; cin >> className;
			createNewClass(pYearHead, nClass, semesterInput, yearInput, className);
			cout << "Done creating class\n\n";

			delete []yearInput;
			delete []semesterInput;
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
			createNewSemester(pYearHead, nSemester, semesterInput, yearInput);
			cout << "Done creating semester\n\n";

			delete []yearInput;
			delete []semesterInput;
		}

		if (respond == 8) {
			cout << "Please input the year: ";
			char *yearInput = new char[21]; cin >> yearInput;
			cout << "Please input the semester: ";
			char *semesterInput = new char[21]; cin >> semesterInput;
			addNewCourse(pCourseHead, nCourse, semesterInput, yearInput);
			cout << "Done adding course\n\n";

			delete []yearInput;
			delete []semesterInput;
		}

		if (respond == 10) {
			updateCourse(pCourseHead);			
			cout << "Done updating course\n\n";
		}

		if (respond == 11) {
			cout << "Please input the course ID you wish to delete: ";
			char *courseID = new char[21]; cin >> courseID;
			cout << "Done deleting course\n\n"; 
			delete(pCourseHead, courseID);
			delete []courseID;
		}

		if (respond == 0) { // End the program
			break;
		}
	}
}
