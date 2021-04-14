#include<bits/stdc++.h>
#include "Course.h"
#include "Header.h"

using namespace std;

void ViewListOfCourse (Course *pCourse) {
    while (pCourse) {
        cout << "Course ID and Name: " << pCourse->id << " " << pCourse->name << endl;
        cout << "Occur in: " << pCourse->date.d1 << " " << pCourse->date.s1 << " and " << pCourse->date.d2 << " " << pCourse->date.s2 << endl;
        
        // move to next course
        pCourse = pCourse -> courseNext;
    }
}
