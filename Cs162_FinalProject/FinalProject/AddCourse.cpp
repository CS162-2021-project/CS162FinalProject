#include <iostream>
#include <fstream>
#include "string.h"
#include "Course.h"
#include "Header.h"

using namespace std;

void addNewCourse(Course*& pCourse, char* semesterName, char* yearName, Course *& newCourse, int add) {
   	Course * pCur = pCourse;
   	while (pCur != nullptr) {
   		if (strcmp(pCur -> id, newCourse -> id) == 0) {
   			while (true) {
   				cout << "A course with the same ID has already existed in this semester\n";
   				cout << "Do you want to replace it?\n";

				cout << "Your input: ";
				char *respond = new char[101]; cin >> respond;
				system("cls");
				if (strlen(respond) > 1 || (respond[0] < '0' || '9' < respond[0])) {
					cout << "Invalid, please try again\n\n";
					continue;
				}
				if (respond[0] - '0' == 0) return;
				else break;
   			}
   		}
   		pCur = pCur -> courseNext;
   	}
    char dirD[] = "C:\\Github\\CS162FinalProject\\Data\\";
    char c[500] = "";
    strcat(c, dirD);
    strcat(c, yearName);
    strcat(c, "\\Semester\\");
    strcat(c, semesterName);
    strcat(c, "\\Course.txt");

    ofstream fout;

    if (add == 1)
	    fout.open(c);

   	pCur = pCourse;

    if (!pCourse) {
        pCourse = newCourse;
        pCur = pCourse;
    }
    else {
        while (pCur -> courseNext) {
            pCur = pCur -> courseNext;
        }
        pCur -> courseNext = newCourse;
        pCur = pCur -> courseNext;
    }
    // get info
    if (add == 1) {
    	pCur = pCourse;
    	while (pCur != nullptr) {
	        fout << pCur -> id << '\n';
	        fout << pCur -> name << '\n';
	        fout << pCur -> lecturerName << '\n';
	        fout << pCur -> numberOfCredits << '\n';
	        fout << pCur -> maxStudent << '\n';
	        fout << pCur -> date.d1 << '\n' << pCur->date.s1 << '\n';
	        fout << pCur -> date.d2 << '\n' << pCur->date.s2 << '\n';
	        pCur = pCur -> courseNext;
	    }
 	}

    if (add == 1)
	    fout.close();
}
