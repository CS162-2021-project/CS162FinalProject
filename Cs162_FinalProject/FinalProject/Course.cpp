#include<bits/stdc++.h>
#include<string.h>
#include "Course.h"
#include "Header.h"

using namespace std;


void deleteCourse (Course*& pHead, char *courseID) {
    if (strcmp(pHead->id,courseID) == 0) {
        Course *pDel = pHead;
        pHead = pHead->pNext;
        delete pDel;
    } else {
        Course *pCur = pHead;
        while (pCur->pNext && strcmp(pCur->pNext->id,courseID) != 0) {
            pCur = pCur->pNext;
        }
        Course *pDel = pCur->pNext;
        pCur->pNext = pDel->pNext;
        delete pDel;
    }
}


// a course registration session is active,student can do :

void registrationSession() {   //unfinished ,im choking, you can delete it if you want :)
	cout << "You have to log in to the system first:";
	// Login to the system
	int n;
	cout << "Choose one of these function:" << endl;
	cout << "1.Enroll in a course." << endl;
	cout << "2.View list of enrolled courses." << endl;
	cout << "3.Remove a course from the enrolled list." << endl;
	cout << "Which one you want to do ? Please input a number:";
	cin >> n;
	switch(n)
	{
	case 1 : //enroll in a course
		break;
	case 2 : //List of enrolled student
		break;
	case 3 : // remove course
		break;
	default:
		break;
	}
}

void enrollInACourse(Course* pHead , Course*& pEnrolledCourse) { //unfinished
	char ID[101];
	int cnt = 0;
	cout << "Course available:" << endl;
	viewListOfCourse(pHead);
	cout << "PLease input the ID of Course in which you want to enroll :";
	cin.ignore(1001, '\n');
	cin.get(ID, 101, '\n');	
	//unfinished
}
