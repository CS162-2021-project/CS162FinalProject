#include<bits/stdc++.h>
#include "Course.h"
#include "Header.h"

using namespace std;

void addNewCourse(Course*& pCourse, char* semesterName, char* yearName) {
    char dirD[] = "C:\\Github\\CS162FinalProject\\Data\\";
    char c[500] = "";
    strcat(c, dirD);
    strcat(c, yearName);
    strcat(c, "\\");
    strcat(c, semesterName);
    strcat(c, "\\course.txt");

    //

    ofstream fout;
    fout.open(c , std::ios_base::app);
    if (fout.is_open()) {
        Course* pCur = pCourse;
        if (!pCourse) {
            pCourse = new Course;
            pCur = pCourse;
        }
        else {
            while (pCur->pNext) {
                pCur = pCur->pNext;
            }
            pCur->pNext = new Course;
            pCur = pCur->pNext;
        }
        // get info
        cin.ignore(1001, '\n');
        cin.get(pCur->id, 101, '\n');
        fout << pCur->id << endl;

        cin.ignore(1001, '\n');
        cin.get(pCur->name, 101, '\n');
        fout << pCur->name << endl;

        cin.ignore(1001, '\n');
        cin.get(pCur->lecturerName, 101, '\n');
        fout << pCur->lecturerName << endl;

        cin >> pCur->numberOfCredits;
        fout << pCur->numberOfCredits << endl;
        
        cin >> pCur->maxStudent;
        fout << pCur->maxStudent << endl;

        cout << " the session that the course will be performed (MON / TUE / WED / THU / FRI / SAT)" << endl;
        cout << " and shift S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30))" << endl;
        cout << "Please input 2 sesstions :" << endl;
        cin >> pCur->date.d1 >> pCur->date.s1;
        cin >> pCur->date.d2 >> pCur->date.s2;
        fout << pCur->date.d1 << ' ' << pCur->date.s1 << endl;
        fout << pCur->date.d2 << ' ' << pCur->date.s2 << endl;
    }
    fout.close();
}
