#include <iostream>
#include <fstream>
#include <string.h>

#include "Header.h"
#include "Student.h"

using namespace std;

void enrollStudent(Course *& pCourse, Student *& pStudent, char* CourseID, char* StudentID, char * yearName, char * semesterName, int add) { 
	Course *curCourse = pCourse;
	while (curCourse && strcmp(curCourse -> id, CourseID) != 0) {
		curCourse = curCourse -> courseNext;
	}

	Student *curStudent = pStudent;
	while (curStudent && strcmp(curStudent -> studentID, StudentID) != 0) {
		curStudent = curStudent -> studentNext;
	}

	Course * tmpCourse = curStudent -> pCourse;
	while (tmpCourse) {
		if (strcmp(tmpCourse -> id, CourseID) == 0) {
			cout << "The student has already enrolled in this course, cannot enrolled!\n\n";
			return;
		}
		tmpCourse = tmpCourse -> courseNext;
	}

	int d1, d2, s1, s2;

	if (strcmp(curCourse -> date.d1, "MON") == 0) d1 = 2;
	else if (strcmp(curCourse -> date.d1, "TUE") == 0) d1 = 3;
	else if (strcmp(curCourse -> date.d1, "WED") == 0) d1 = 4;
	else if (strcmp(curCourse -> date.d1, "THU") == 0) d1 = 5;
	else if (strcmp(curCourse -> date.d1, "FRI") == 0) d1 = 6;
	else if (strcmp(curCourse -> date.d1, "SAT") == 0) d1 = 7;
	s1 = (curCourse -> date.s1)[1] - '0';

	if (strcmp(curCourse -> date.d1, "MON") == 0) d1 = 2;
	else if (strcmp(curCourse -> date.d1, "TUE") == 0) d1 = 3;
	else if (strcmp(curCourse -> date.d1, "WED") == 0) d1 = 4;
	else if (strcmp(curCourse -> date.d1, "THU") == 0) d1 = 5;
	else if (strcmp(curCourse -> date.d1, "FRI") == 0) d1 = 6;
	else if (strcmp(curCourse -> date.d1, "SAT") == 0) d1 = 7;
	s2 = (curCourse -> date.s2)[1] - '0';


	if (curStudent -> enrolledSession[d1][s1] || curStudent -> enrolledSession[d2][s2]) {
		cout << "The current course has sessions that are conflict with existing enrolled course sessions, cannot enrolled!\n\n";
		return;
	}                                   
	
	int sz_enroll = 0;
	Course* enrollCourse = curStudent -> pCourse;
	while (enrollCourse) {
		sz_enroll++;
		enrollCourse = enrollCourse -> courseNext;
	}
	if (sz_enroll >= 5) {
		cout << "The student has already enrolled in 5 courses, cannot enrolled!\n\n";
		return;
	}

	int sz_student = 0;
	Student* stuInCourse = curCourse -> pStudent;
	while(stuInCourse) {
		sz_student++;
		stuInCourse = stuInCourse -> studentNext;
	}
	if (sz_student >= curCourse -> maxStudent) {
		cout << "The course is already full, cannot enrolled!\n\n";
		return;
	}

		
	curStudent -> enrolledSession[d1][s1] = true;
	curStudent -> enrolledSession[d2][s2] = true;

	enrollCourse = curStudent -> pCourse;
	if (enrollCourse == nullptr) {
		curStudent -> pCourse = new Course;
		enrollCourse = curStudent -> pCourse;
	}
	else {
		while (enrollCourse -> courseNext)
			enrollCourse = enrollCourse -> courseNext;
		enrollCourse -> courseNext = new Course;
		enrollCourse = enrollCourse -> courseNext;
	}

	enrollCourse -> id = new char[51];
	strcpy(enrollCourse -> id, curCourse -> id);
	enrollCourse -> name = new char[51];
	strcpy(enrollCourse -> name, curCourse -> name);
	enrollCourse -> lecturerName = new char[51];
	strcpy(enrollCourse -> lecturerName, curCourse -> lecturerName);
	enrollCourse -> numberOfCredits = curCourse -> 	numberOfCredits;
	enrollCourse -> maxStudent = curCourse -> maxStudent;
	enrollCourse -> date.d1 = new char[51]; 
	strcpy(enrollCourse -> date.d1, curCourse -> date.d1);
	enrollCourse -> date.s1 = new char[51]; 
	strcpy(enrollCourse -> date.s1, curCourse -> date.s1);
	enrollCourse -> date.d2 = new char[51]; 
	strcpy(enrollCourse -> date.d2, curCourse -> date.d2);
	enrollCourse -> date.s2 = new char[51]; 
	strcpy(enrollCourse -> date.s2, curCourse -> date.s2);

	stuInCourse = curCourse -> pStudent;
	if (stuInCourse == nullptr) {
		curCourse -> pStudent = new Student;
		stuInCourse = curCourse -> pStudent;
	}
	else {
		while(stuInCourse -> studentNext)
			stuInCourse = stuInCourse -> studentNext;
		stuInCourse -> studentNext = new Student;
		stuInCourse = stuInCourse -> studentNext;
	}

	stuInCourse -> studentID = new char[51];
	strcpy(stuInCourse -> studentID, curStudent -> studentID);
	stuInCourse -> Name = new char[51];
	strcpy(stuInCourse -> Name, curStudent -> Name);
	stuInCourse -> DOB = curStudent -> DOB;
	stuInCourse -> sClass = new char[51];
	strcpy(stuInCourse -> sClass, curStudent -> sClass);
	stuInCourse -> gender = curStudent -> gender;

	cout << "Enroll successfully!\n\n";
	system("pause");
	system("cls");
	if (add == 1) {
		char *dir = new char[505];
		strcat(dir, "C:\\Github\\CS162FinalProject\\Data\\");
		strcat(dir, yearName);
		strcat(dir, "\\Semester\\");
		strcat(dir, semesterName);
		strcat(dir, "\\");
		strcat(dir, CourseID);

		char *mkdir = new char[505];
		strcat(mkdir, "mkdir ");
		strcat(mkdir, dir);

		system(mkdir);
		system("cls");
		strcat(dir, "\\Student.txt");
		ofstream fOut(dir);

		stuInCourse = curCourse -> pStudent;
		while (stuInCourse) {
			fOut << stuInCourse -> studentID << '\n';
			stuInCourse = stuInCourse -> studentNext;
		}

		fOut.close();
	}
}