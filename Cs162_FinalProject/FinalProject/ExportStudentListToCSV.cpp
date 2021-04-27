#include "Header.h"
#include "Staff.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void exportStudentToCsv(Student* pStuInCourse, char *courseID) {
	char dirD[] = "C:\\Github\\CS162FinalProject\\Data\\Student_csv\\";
	char c[505];
	strcat(c, dirD);
	strcat(c, courseID);
	strcat(c, ".csv");
	ofstream fout;
	fout.open(c);
	if (fout.is_open()) {
		int cnt = 0;
		while (pStuInCourse) {
			fout << ++cnt << "," << pStuInCourse->studentID << "," << pStuInCourse->Name << "," << pStuInCourse->DOB.year << "-" << pStuInCourse -> DOB.month << "-" << 
			pStuInCourse -> DOB.day << "," << pStuInCourse->sClass << "," << pStuInCourse->gender;
			fout << '\n';
			pStuInCourse = pStuInCourse->studentNext;
		}
		cout << "Done! The list of students has been exported into the file CS162FinalProject\\Data\\Student_csv\\" << courseID << ".csv\n\n";
		system("pause");
		system("cls");
	}
	fout.close();
}