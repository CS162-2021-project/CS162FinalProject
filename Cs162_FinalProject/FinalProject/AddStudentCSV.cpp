#include <bits/stdc++.h>
#include "Header.h"
#include "Class.h"

using namespace std;

void inputStudentCSV(Student *&newStu, char *s) {
	int t = 0, n = strlen(s);
	char *cur = new char[50], pos = 0;
	for (int i = 0; i < n; i++) {
		if (i == n - 1 || s[i] == ',') {
			if (t == 0) {
				// Doing nothing
			}
			else if (t == 1) {
				newStu -> studentID = new char[pos];
				int l = strlen(cur);
				for (int i = 0 ; i < l; i++)
					newStu -> studentID[i] = cur[i];
				newStu -> studentID[l] = '\0';					
			} 
			else if (t == 2) {
				newStu -> Name = new char[pos];
				int l = strlen(cur);
				for (int i = 0 ; i < l; i++)
					newStu -> Name[i] = cur[i];
				newStu -> Name[l] = '\0';
			}
			else if (t == 3) {
				int y = (cur[0] - '0') * 1000 + (cur[1] - '0') * 100 + (cur[2] - '0') * 10 + (cur[3] - '0');
				int m = (cur[5] - '0') * 10 + (cur[6] - '0');
				int d = (cur[8] - '0') * 10 + (cur[9] - '0');
			}
			else if (t == 4) {
				// Doing nothing		
			}
			else if (t == 5) {
				newStu -> gender = cur[0] - '0';
			}
			t++;
			pos = 0;
		}
		else 
			cur[pos++] = s[i];
	} 
}

void addStudentCSV(Student*& pStudent, char* CSV_Student_File, char* yearName, char* className) {
	char dirOut[] = { "C:\\Github\\CS162FinalProject\\Data\\" };
	char d[505] = "";
	strcat(d, dirOut);
	strcat(d, yearName);
	strcat(d, "\\");
	strcat(d, className);
	strcat(d, "\\");
	strcat(d, "Student.txt");

	ofstream fOut(d);

	char dirIn[] = { "C:\\Github\\CS162FinalProject\\Data\\File_csv\\" };
	char dd[500] = { "" };
	strcat(dd, CSV_Student_File);

	ifstream fIn(dd);

	char* s = new char[500];
	while (fIn.getline(s, 505)) {
		Student *newStu = new Student;
	    inputStudentCSV(newStu, s);
	
		if (pStudent == nullptr) {
			pStudent = newStu;
			pStudent -> studentNext = nullptr;
		}
		else {
			Student* pCur = pStudent;
			while (pCur -> studentNext != nullptr)
				pCur = pCur -> studentNext;
			pCur -> studentNext = newStu;
			pCur = pCur -> studentNext;
			pCur -> studentNext = nullptr;
		}
	}
	Student *pCur = pStudent;
	while (pCur != nullptr) {
		fOut << pCur -> studentID << ' ' << pCur -> Name << ' ' << pCur -> DOB.month << "-" << pCur -> DOB.day << "-" << pCur -> DOB.year << ' ' << pCur -> gender;
		pCur = pCur -> studentNext;
	}
}