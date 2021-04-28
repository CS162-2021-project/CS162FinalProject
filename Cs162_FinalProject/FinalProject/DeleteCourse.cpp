#include <iostream>
#include <fstream>
#include <string.h>

#include"Header.h"
#include"Course.h"

using namespace std;

void deleteCourse(Year * pYear, Course*& pCourse, char* yearName, char* semesterName, char* courseID) {
	while(1) {
		cout << "Are you sure you want to delete this course?\n\n";
		cout << "0: No\n";
		cout << "1: Yes\n\n";

   		cout << "Your input: ";
   		char *respond = new char[101]; cin >> respond;
   		system("cls");
   		if (strlen(respond) > 1 || (respond[0] < '0' || '1' < respond[0])) {
   			cout << "Invalid, please try again\n\n";
   			continue;
   		}
   		int x = respond[0] - '0';
   		delete[] respond;
   		if (x)
   			return;
   		break;		
	}

 	// Then we simply delete this course

    if (strcmp(pCourse->id, courseID) == 0) {
        Course* pDel = pCourse;
        pCourse = pCourse->courseNext;
        delete pDel;
    }
    else {
        Course* pCur = pCourse;
        while (pCur->courseNext && strcmp(pCur->courseNext->id, courseID) != 0) {
            pCur = pCur -> courseNext;
        }
        if (pCur->courseNext) {
            Course* pDel = pCur->courseNext;
            pCur->courseNext = pDel->courseNext;
            delete pDel;
        }
    }
	char dirD[] = "C:\\Github\\CS162FinalProject\\Data\\";
    char c[500] = "";
    strcat(c, dirD);
    strcat(c, yearName);
    strcat(c, "\\Semester\\");
    strcat(c, semesterName);
    strcat(c, "\\Course.txt");

    ofstream fout(c);

    Course * pCur = pCourse;
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
 	fout.close();
}