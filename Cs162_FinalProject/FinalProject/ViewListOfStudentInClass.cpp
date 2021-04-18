#include"Header.h"
#include"Course.h"
#include"Staff.h"
#include<iostream>
using namespace std;

void viewListOfStudentsInClass(Year* pYear, char* className) {
	while (pYear) {
		while (pYear->pClass) {
			if (strcmp(pYear->pClass->ClassName, className) == 0) {
				while (pYear->pClass->pStudent) {
					viewStudentInfo(pYear->pClass->pStudent);
					pYear->pClass->pStudent = pYear->pClass->pStudent->studentNext;
				}
			}
			pYear->pClass = pYear->pClass->classNext;
		}
		pYear = pYear->yearNext;
	}
}

void viewStudentInfo(Student student) {
	cout << "Student name : " << student.name << endl;
	cout << "Student ID : " << student.studentID << endl;
	if (student.gender)
		cout << "female" << endl;
	else cout << "male" << endl;
}