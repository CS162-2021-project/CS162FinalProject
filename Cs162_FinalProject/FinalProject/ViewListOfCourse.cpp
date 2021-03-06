#include <iostream>
#include "Course.h"
#include "Header.h"

using namespace std;

void viewListOfCourse (Course *pCourse) {
	Course * pCur = pCourse;
    while (pCur != nullptr) {
        cout << "Course ID: " << pCur -> id << '\n';
        cout << "Course Name: " << pCur -> name << '\n';
        cout << "Lecturer Name: " << pCur -> lecturerName << '\n';
		cout << "Number of Credit: " << pCur -> numberOfCredits << '\n';
        cout << "Occur in: " << pCur -> date.d1 << " " << pCur -> date.s1 << " and " << pCur -> date.d2 << " " << pCur -> date.s2 << '\n';
        int cnt = 0;
        Student* stuInCourse = pCur -> pStudent;
        while (stuInCourse != nullptr) {
        	cnt++;
        	stuInCourse = stuInCourse -> studentNext;
        }
		cout << "Number of students registered: " << cnt << " / " << pCur -> maxStudent << '\n';
		cout << '\n';

        // move to next course
        pCur = pCur -> courseNext;
    }
    system("pause");
    system("cls");
}
