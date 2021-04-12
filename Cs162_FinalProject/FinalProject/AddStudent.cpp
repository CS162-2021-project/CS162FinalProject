#include <bits/stdc++.h>
#include "Header.h"
#include "Class.h"

using namespace std;

void inputStudent(Student &newStu) {
	Student stu;
	cout << "Input the student's ID: ";
	stu.ID = new char[21];
	cin >> stu.ID;

	cout << "Input the student's name: ";
	stu.sName = new char[21];
	cin >> stu.sName;

	cout << "Input the student's date of birth.\n";
	cout << "Year? ";
	cin >> stu.DOB.year;
	cout << "Month? ";
	cin >> stu.DOB.month;
	cout << "Day? ";
	cin >> stu.DOB.day;
	cin.get();

	cout << "Input the student's gender(type 1 if male, 0 if female): ";
	cin >> stu.gender;
	cin.get();
}

void addStudent(Student*& pStudent, char* yearName, char* className) {
	cout << "Please input the year: ";
	char *yearInput = new char[21]; cin >> yearInput;
	cout << "Please input the semester: ";
	char *semesterInput = new char[21]; cin >> semesterInput;
	cout << "Please input the class name: ";
	char *className = new char[21]; cin >> className;

	char dirD[] = { "C:/Github/CS162FinalProject/Data/" };
	char d[505] = { "" };
	strcat_s(d, 500, dirD);
	strcat_s(d, 500, year);
	strcat_s(d, 500, "/");
	strcat_s(d, 500, seme);
	strcat_s(d, 500, "/");
	strcat_s(d, 500, className);
	strcat_s(d, 500, "/");
	strcat_s(d, 500, "Student.txt");

	Student newStu;
    inputStudent(newStu);

	ofstream fOut(d);
}

void addStudentByCSV() {

}