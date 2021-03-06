#include <iostream>
#include <fstream>
#include <string.h>

#include "Header.h"
#include "Course.h"

using namespace std;
void updateCourse(Course*& pCourse, char* yearName, char* semesterName, char* courseID) {
    Course* pCur = pCourse;
    while (pCur && strcmp(pCur->id, courseID) != 0) {
        pCur = pCur->courseNext;
    }
    
    int x;
    while(1) {
    	cout << "0: Go back\n\n";

	    cout << "Choose 1 of these functions:\n";
	    cout << "1: Course's ID" << endl;
	    cout << "2: Course's name" << endl;
	    cout << "3: Lecturer's name" << endl;
	    cout << "4: Number of credits" << endl;
	    cout << "5: Max students" << endl;
	    cout << "6: Session and Shifts" << endl;
	    cout << "Which information do you want to update?" << "\n\n";

   		cout << "Your input: ";
   		char *respond = new char[101]; cin >> respond;
   		system("cls");
   		if (strlen(respond) > 1 || (respond[0] < '0' || '9' < respond[0])) {
   			cout << "Invalid, please try again\n\n";
   			continue;
   		}
   		x = respond[0] - '0';
   		break;
	}

	if (x == 0)
		return;

    if (x == 1) {
        cout << "New course's ID: ";
        cin.ignore(1001, '\n');
        cin.get(pCur->id, 101, '\n');
    }
    else if (x == 2) {
        cout << "New course's name: ";
        cin.ignore(1001, '\n');
        cin.get(pCur->name, 101, '\n');
    }
    else if (x == 3) {
        cout << "New lecturer's name: ";
        cin.ignore(1001, '\n');
        cin.get(pCur->lecturerName, 101, '\n');
    }
    else if (x == 4) {
        cout << "New number of credits: ";
        cin >> pCur->numberOfCredits;
    }
    else if (x == 5) {
        cout << "New max students: ";
        cin >> pCur->maxStudent;
    }
    else {
        cout << "New day 1 and shift 1: ";
        cin >> pCur->date.d1 >> pCur->date.s1;
        cout << "New day 2 and shift 2: ";
        cin >> pCur->date.d2 >> pCur->date.s2;
    }
    cout << "Update successfully!!\n";
    system("pause");
    system("cls");

    char dirD[] = "C:\\Github\\CS162FinalProject\\Data\\";
    char c[500] = "";
    strcat(c, dirD);
    strcat(c, yearName);
    strcat(c, "\\Semester\\");
    strcat(c, semesterName);
    strcat(c, "\\Course.txt");

    ofstream fout(c);

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
	fout.close();
}
