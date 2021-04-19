#include"Header.h"
#include"Staff.h"
#include<iostream>
#include<fstream>

using namespace std;

void exportStudentToCsv(Student* pStuInCourse) {
	ofstream fout;
	fout.open("C:\\Github\\CS162FinalProject\\Data\\File_csv\\Student.csv");
	if (fout.is_open()) {
		while (pStuInCourse) {
			fout << pStuInCourse->studentID << "," << pStuInCourse->Name << "," << pStuInCourse->DOB << "," << pStuInCourse->sClass << "," << pStuInCourse->gender;
			fout << endl;
			pStuInCourse = pStuInCourse->studentNext;
		}
	}
	fout.close();
}