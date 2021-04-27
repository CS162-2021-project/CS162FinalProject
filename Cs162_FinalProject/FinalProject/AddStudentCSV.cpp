#include <fstream>
#include <string.h>
#include "Header.h"
#include "Class.h"

using namespace std;

void inputStudentCSV(Student *&newStu, char *s) {
	int t = 0, n = strlen(s);
	int pos = 0;
	char *cur = new char[50];
	for (int i = 0; i < n; i++) {
		if (i == n - 1 || s[i] == ',') {
			if (t == 0) {
				// Doing nothing
			}
			else if (t == 1) {
				newStu -> studentID = new char[pos + 10];
				for (int j = 0 ; j < pos; j++)
					newStu -> studentID[j] = cur[j];
				newStu -> studentID[pos] = '\0';					
			} 
			else if (t == 2) {
				newStu -> Name = new char[pos + 10];
				for (int j = 0 ; j < pos; j++)
					newStu -> Name[j] = cur[j];
				newStu -> Name[pos] = '\0';
			}
			else if (t == 3) {
				newStu -> DOB.year = (cur[0] - '0') * 1000 + (cur[1] - '0') * 100 + (cur[2] - '0') * 10 + (cur[3] - '0');
				newStu -> DOB.month = (cur[5] - '0') * 10 + (cur[6] - '0');
				newStu -> DOB.day = (cur[8] - '0') * 10 + (cur[9] - '0');
			}
			else if (t == 4) {
				// Doing nothing		
			}
			else if (t == 5) {
				newStu -> gender = s[i] - '0';
			}
			t++;
			pos = 0;
		}
		else 
			cur[pos++] = s[i];
	} 
}

void addStudentCSV(Student*& pStudent, char* CSV_Student_File, char* yearName, char* className, int add) {
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
	char dd[505] = "";
	strcat(dd, dirIn);
	strcat(dd, CSV_Student_File);

	ifstream fIn(dd);

	char* s = new char[505];
	while (fIn.getline(s, 505)) {
		Student *newStu = new Student;
	    inputStudentCSV(newStu, s);
	
		if (pStudent == nullptr)
			pStudent = newStu;
		else {
			Student* pCur = pStudent;
			while (pCur -> studentNext != nullptr)
				pCur = pCur -> studentNext;
			pCur -> studentNext = newStu;
			pCur = pCur -> studentNext;
		}
	}

	Student *pCur = pStudent;
	while (pCur != nullptr) {
		if (add)
			fOut << pCur -> studentID << ',' << pCur -> Name << ',' << pCur -> DOB.year << "-" << pCur -> DOB.month << "-" << pCur -> DOB.day << ',' << pCur -> gender << '\n';
		pCur = pCur -> studentNext;
	}
}