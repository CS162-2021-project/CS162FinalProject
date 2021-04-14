//#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include "Staff.h"
#include "Header.h"

using namespace std;

bool isExistCourse(char courseID[], char year[], char semester[], char className[], char fileAdd[], int& maxno) {
	ifstream in;
	char a[200] = {};
	strcat(a, "E:\\Github\\CS162FinalProject\\Data\\");
	strcat(a, year);
	strcat(a, "\\");
	strcat(a, semester);
	strcat(a, "\\");
	strcat(a, className);
	strcat(a, "\\Schedule.txt");
	strcpy(fileAdd, a);
	in.open(fileAdd);
	if (!in.is_open()) {
		cout << "Error open schedule.txt.\n";
		exit(0);
	}
	//maxno = countLine(in, 19);
	in.close();
	in.open(fileAdd);
	if (!in.is_open()) {
		cout << "error openning at isExistCourse function\n";
		exit(0);
	}
	else {
		char a[200];
		while (!in.eof()) {
			in.get(a, 200, '\n');
			in.ignore(200, '\n');
			if (/*isSameStr(a, courseID)*/true) {
				in.close();
				return true;
			}
		}
	}
	in.close();
	return false;
}

void inputCourse(schedule& c, char year[], char semester[], char className[], char fileAdd[]) {
	system("cls");
	cout << "=== PLEASE INPUT SOME INFORMATION ===\n";
	char id[20];
	cout << "Course ID: ";
	cin.ignore(200, '\n');
	cin.get(id, 20, '\n');


	//check if the course is existing
	int maxno = 0;
	if (isExistCourse(id, year, semester, className, fileAdd, maxno)) {
		system("cls");
		cout << "The course has already create please try again\n";
		system("pause");
		inputCourse(c, year, semester, className, fileAdd);
	}
	else {
		//
		char ad[200] = {};
		strcat(ad, "E:\\Github\\CS162FinalProject\\Data\\");
		strcat(ad, year);
		strcat(ad, "\\");
		strcat(ad, semester);
		strcat(ad, "\\");
		strcat(ad, className);
		strcat(ad, "\\");
		strcat(ad, id);
		strcat(ad, ".txt");
		ofstream out(ad);
		//
		cin.ignore(100, '\n');
		//inputCourseData(c, id, maxno, className);
	}
}