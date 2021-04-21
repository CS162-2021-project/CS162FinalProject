#include <bits/stdc++.h>

#include "Header.h"
#include "Course.h"

using namespace std;
void updateCourse(Course*& pCourse, char* courseID) {
    Course* pCur = pCourse;
    while (pCur && strcmp(pCur->id, courseID) != 0) {
        pCur = pCur->courseNext;
    }

    cout << "Choose 1 of these functions:";
    cout << "1. Course ID" << endl;
    cout << "2. Course name" << endl;
    cout << "3. Lecturer name" << endl;
    cout << "4. Number of credits" << endl;
    cout << "5. Max students" << endl;
    cout << "6. Session and Shifts" << endl;
    cout << "which information you want to update?" << endl;
    int x;
    cin >> x;

    if (x == 1) {
        cout << "New course ID:";
        cin.ignore(1001, '\n');
        cin.get(pCur->id, 101, '\n');
    }
    else if (x == 2) {
        cout << "New course name:";
        cin.ignore(1001, '\n');
        cin.get(pCur->name, 101, '\n');
    }
    else if (x == 3) {
        cout << "New lecturer name:";
        cin.ignore(1001, '\n');
        cin.get(pCur->lecturerName, 101, '\n');
    }
    else if (x == 4) {
        cout << "New number of credits:";
        cin >> pCur->numberOfCredits;
    }
    else if (x == 5) {
        cout << "New max students:";
        cin >> pCur->maxStudent;
    }
    else {
        cout << "New day 1 and shift 1:";
        cin >> pCur->date.d1 >> pCur->date.s1;
        cout << "New day 2 and shift 2:";
        cin >> pCur->date.d2 >> pCur->date.s2;
    }
}
