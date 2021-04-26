#include<string.h>
#include "Staff.h"
#include "Header.h"
#include<iostream>

using namespace std;

void viewListOfStudentsInCourse (Student *pStuInCourse) {
    while (pStuInCourse) {
        cout << pStuInCourse->studentID << "\t" << pStuInCourse->Name << "\t" << pStuInCourse->DOB.day << "/" << pStuInCourse->DOB.month << "/"  <<  pStuInCourse->DOB.year << "\t" << pStuInCourse->sClass << "\t" << pStuInCourse->gender << endl;
        pStuInCourse = pStuInCourse -> studentNext;
    }
}
