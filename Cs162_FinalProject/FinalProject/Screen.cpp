#include <sstream>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string.h>
#include "Header.h"
#include "Class.h"
#include "Course.h"
#include "Staff.h"
#include "Student.h"
#include "System.h"

using namespace std;

int chooseRoleScreen() {
	while(1) {
		cout << "Please input your choice: \n";
		cout << "0: Exit the programme\n";
		cout << "1: Access as a staff\n";
		cout << "2: Access as a student\n";

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 1 || (respond[0] < '0' || '9' < respond[0])) {
			cout << "Invalid, please try again\n\n";
			continue;
		}

		return respond[0] - '0';
	}
}

int yearScreen() {
	while(1) {
		cout << "Please input your choice Staff: \n";
		cout << "0: Logout\n";
		cout << "1: Create a new school year\n";
		char *s = new char[51];
		int cnt = 2;
		ifstream fIn("C:\\Github\\CS162FinalProject\\Data\\Year.txt");
		while(fIn >> s)
			cout << cnt++ << ": Access year " << s << '\n';
		delete[] s;
	
		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 1 || (respond[0] < '0' || '9' < respond[0])) {
			cout << "Invalid, please try again\n\n";
			continue;
		}

		return respond[0] - '0';
	}
}

void createYearScreen(Year *& pYear) {
	cout << "Please input the new school year name: \n";
	char *yearName = new char[101];
	cin >> yearName;
	createNewYear(pYear, yearName, 1);
	system("cls");
}

int classScreen(char* yearName) {
	char dir[101] = "C:\\Github\\CS162FinalProject\\Data\\";
	strcat(dir, yearName);
	strcat(dir, "\\Class.txt");
	while(1) {
		cout << "Year: " << yearName << "\n\n";

		cout << "Please input your choice: \n";
		cout << "0: Go back\n";
		cout << "1: Check all semesters\n";
		cout << "2: Create a new class\n";
		char *s = new char[51];
		int cnt = 3;
		ifstream fIn(dir);
		while(fIn >> s)
			cout << cnt++ << ": Access class " << s << '\n';
		delete[] s;
	
		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 1 || (respond[0] < '0' || '9' < respond[0])) {
			cout << "Invalid, please try again\n\n";
			continue;
		}

		return respond[0] - '0';
	}
}

void createClassScreen(Class *& pClass, char * yearName) {
	cout << "Please input the new class name: \n";
	char *className = new char[101];
	cin >> className;
	createNewClass(pClass, yearName, className, 1);
	system("cls");
}

int studentScreen(Student * pStudent, char* yearName, char* className) {
	while(1) {
		char *s = new char[51];
		int cnt = 1, t = 0;
	
		cout << "Class: " << className << "\n\n";

		Student * curStudent = pStudent;
		while (curStudent != nullptr) {
			cout << cnt++ << ' ' << curStudent -> studentID << ' ' << curStudent -> Name << ' ' << ((curStudent -> gender) ? "Female" : "Male") << ' ' << 
					curStudent -> DOB.month << '/' << curStudent -> DOB.day << '/' << curStudent ->DOB.year << '\n';
			curStudent = curStudent -> studentNext;
		}	

		cout << "Please input your choice: \n";
		cout << "0: Go back\n";
		cout << "1: Create a new student\n";
		cout << "2: Add students through .csv file\n";
		cout << "3: View scoreboard of the class\n";
	
		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 1 || (respond[0] < '0' || '9' < respond[0])) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		return respond[0] - '0';
	}
}

void createStudentScreen(Student *& pStudent, char* yearName, char* className) {
	Student *newStu = new Student;
	inputStudent(newStu);
	addStudent(pStudent, yearName, className, newStu, 1);
}

void createStudentCSVScreen(Student *& pStudent, char* yearName, char* className) {
	cout << "Please drag the .csv file you wish to import into the directory CS162FinalProject\\Data\\File_csv\n";
	cout << "Also, please input the name of the file: ";
	char *csvFile = new char[101];
	cin >> csvFile;
	addStudentCSV(pStudent, csvFile, yearName, className, 1);
}

int semesterScreen(Semester *& pSemester) {
	while(1) {
		cout << "Please input your choice: \n";

		cout << "0: Go back\n";
		cout << "1: Create a new semester\n";

		int cnt = 2;
		Semester * pCur = pSemester;
		while (pCur != nullptr) {
			cout << cnt++ << ": Access semester " << pCur -> SemesterName << "(From " << pCur->startDate.month << '/' << pCur->startDate.day << '/' << pCur->startDate.year <<
				" to " << pCur->endDate.month << '/' << pCur->endDate.day << '/' << pCur->endDate.year << ")" << '\n';
			pCur = pCur -> semesterNext;
		}

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 1 || (respond[0] < '0' || '9' < respond[0])) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		return respond[0] - '0';
	}
}                     

void createSemesterScreen(Semester *& pSemester, char *yearName) {
	cout << "Please input the new semester name: \n";
	char *semesterName = new char[51];
	cin >> semesterName;

	cout << "Please input the start date of the semester: \n";
	Date startDate;
	cout << "Year?: "; cin >> startDate.year;
	cout << "Month: "; cin >> startDate.month;
	cout << "Day?: "; cin >> startDate.day;

	cout << "Please input the end date of the semester: \n";
	Date endDate;
	cout << "Year?: "; cin >> endDate.year;
	cout << "Month: "; cin >> endDate.month;
	cout << "Day?: "; cin >> endDate.day;

	createNewSemester(pSemester, semesterName, yearName, startDate, endDate, 1);
	system("cls");
}

int courseScreen(Course *& pCourse, char * semesterName) {
	while(1) {
		cout << "Semester: " << semesterName << "\n\n";

		cout << "Please input your choice: \n";
		cout << "0: Go back\n";
		cout << "1: Create a course registration session\n";
		cout << "2: Add a new course\n";
		cout << "3: View list of courses\n";
		
		int cnt = 4;
		Course * pCur = pCourse;
		while (pCur != nullptr) {
			cout << cnt++ << ": Access course " << pCur -> id << '\n';
			pCur = pCur -> courseNext;
		}

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 1 || (respond[0] < '0' || '9' < respond[0])) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		return respond[0] - '0';
	}	
}

void addCourseScreen(Course *& pCourse, char* yearName, char* semesterName) {
	Course * newCourse = new Course;
	                   
	cin.get();
    cout << "Please input the course ID: ";
    newCourse -> id = new char[101];
	cin.getline(newCourse -> id, 50);
    
    cout << "Please input the course name: ";
    newCourse -> name = new char[101];
	cin.getline(newCourse -> name, 50);

    cout << "Please input the course lecturer's name: ";
    newCourse -> lecturerName = new char[101];
	cin.getline(newCourse -> lecturerName, 50);

    cout << "Please input the number of credits: ";
    cin >> newCourse->numberOfCredits;

    cout << "Please input the maximal student: ";
    cin >> newCourse->maxStudent;
    cin.get();

    cout << " the session that the course will be performed (MON / TUE / WED / THU / FRI / SAT)" << endl;
    cout << " and shift S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30))" << endl;
    cout << "Please input 2 sessions :" << endl;
    newCourse -> date.d1 = new char[5];
    newCourse -> date.s1 = new char[5];
    newCourse -> date.d2 = new char[5];
    newCourse -> date.s2 = new char[5];
    cout << "Session 1: ";
	cin.getline(newCourse -> date.d1, 5);
    cout << "Shift 1: "; newCourse->date.s1;
	cin.getline(newCourse -> date.s1, 5);
    cout << "Session 2: ";
	cin.getline(newCourse -> date.d2, 5);
    cout << "Shift 2: "; newCourse->date.s1;
	cin.getline(newCourse -> date.s2, 5);
	addNewCourse(pCourse, semesterName, yearName, newCourse, 1);
	system("cls");
}