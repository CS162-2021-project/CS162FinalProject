#include<iostream>
#include<fstream>
#include<string.h>
#include"Header.h"
#include"Student.h"

using namespace std;

void removeCourseInEnrollList(Course*& pCourse, Student*& pStudent, char *yearName, char *semesterName, char* CourseID, char* studentID) {
	while(1) {
		cout << "Are you sure you want to unenroll from this course?\n\n";
		cout << "0: No\n";
		cout << "1: Yes\n";
		cout << '\n';

   		cout << "Your input: ";
   		char *respond = new char[101]; cin >> respond;
   		system("cls");
   		if (strlen(respond) > 1 || (respond[0] < '0' || '1' < respond[0])) {
   			cout << "Invalid, please try again\n\n";
   			continue;
   		}
   		int x = respond[0] - '0';
   		delete[] respond;
   		if (!x)
   			return;
   		break;		
	}

	int d1, d2, s1, s2;

	if (strcmp(pCourse -> date.d1, "MON") == 0) d1 = 2;
	else if (strcmp(pCourse -> date.d1, "TUE") == 0) d1 = 3;
	else if (strcmp(pCourse -> date.d1, "WED") == 0) d1 = 4;
	else if (strcmp(pCourse -> date.d1, "THU") == 0) d1 = 5;
	else if (strcmp(pCourse -> date.d1, "FRI") == 0) d1 = 6;
	else if (strcmp(pCourse -> date.d1, "SAT") == 0) d1 = 7;
	s1 = (pCourse -> date.s1)[1] - '0';

	if (strcmp(pCourse -> date.d2, "MON") == 0) d2 = 2;
	else if (strcmp(pCourse -> date.d2, "TUE") == 0) d2 = 3;
	else if (strcmp(pCourse -> date.d2, "WED") == 0) d2 = 4;
	else if (strcmp(pCourse -> date.d2, "THU") == 0) d2 = 5;
	else if (strcmp(pCourse -> date.d2, "FRI") == 0) d2 = 6;
	else if (strcmp(pCourse -> date.d2, "SAT") == 0) d2 = 7;
	s2 = (pCourse -> date.s2)[1] - '0';

	pStudent -> enrolledSession[d1][s1] = false;
	pStudent -> enrolledSession[d2][s2] = false;

	Course *& pEnrollCourse = pStudent -> pCourse;
	Student *& pStuInCourse = pCourse -> pStudent;

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

    if (strcmp(pStuInCourse -> studentID, studentID) == 0) {
    	Student* pDel = pStuInCourse;
    	pStuInCourse = pStuInCourse -> studentNext;
    	delete pDel;
    }
    else {
    	Student *pCurStudent = pStuInCourse;
		while(pCurStudent -> studentNext != nullptr && strcmp(pCurStudent -> studentNext -> studentID, studentID) != 0)
			pCurStudent = pCurStudent -> studentNext;
		Student* pDel = pCurStudent -> studentNext;
		pCurStudent -> studentNext = pDel -> studentNext;
		delete pDel;
	}

	char dir[] = "C:\\Github\\CS162FinalProject\\Data\\";
	char c[505] = "";
	strcat(c, dir);
	strcat(c, yearName);
	strcat(c, "\\Semester\\");
	strcat(c, semesterName);
	strcat(c, "\\");
	strcat(c, CourseID);
	strcat(c, "\\Student.txt");
	ofstream fOut(c);


	Student *curStudent = pStuInCourse;
	while (curStudent) {
		fOut << curStudent -> studentID << '\n';
		curStudent = curStudent -> studentNext;
	}

	fOut.close();
}