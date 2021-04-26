#include<iostream>
#include<fstream>
#include<string.h>
#include"Header.h"
#include"Student.h"

using namespace std;

void removeCourseInEnrollList(Course*& pEnrollCourse, char *yearName, char *semesterName, char* CourseID) {
	while(1) {
		cout << "Are you sure to delete this course?\n";
		cout << "0: No\n";
		cout << "1: Yes\n";

   		cout << "Your input: ";
   		char *respond = new char[101]; cin >> respond;
   		system("cls");
   		if (strlen(respond) > 1 || (respond[0] < '0' || '9' < respond[0])) {
   			cout << "Invalid, please try again\n\n";
   			continue;
   		}
   		if (respond[0] - '0' == 0)
   			return;
   		break;		
	}

    if (strcmp(pEnrollCourse -> id, CourseID) == 0) {
    	Course* pDel = pEnrollCourse;
    	pEnrollCourse = pEnrollCourse -> courseNext;
    	delete pDel;
    }
    else {
    	Course * pCur = pEnrollCourse;
		while(pCur -> courseNext != nullptr && strcmp(pCur -> courseNext -> id, CourseID) != 0)
			pCur = pCur -> courseNext;
		Course* pDel = pCur -> courseNext;
		pCur -> courseNext = pDel -> courseNext;
		delete pDel;
	}
	system("cls");

	/*
	char *dir = new char[505];
	strcat(dir, "C:\\Github\\CS162FinalProject\\Data\\");
	strcat(dir, yearName);
	strcat(dir, "\\Semester\\");
	strcat(dir, semesterName);
	strcat(dir, "\\");
	strcat(dir, CourseID);
	strcat(dir, "\\Student.txt");
	ofstream fOut(dir);

	Student * stuInCourse = pCur -> pStudent;
	while (stuInCourse) {
		fOut << stuInCourse -> studentID << '\n';
	}
	*/
}

