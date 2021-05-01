#include <iostream>
#include <string.h>
#include "Header.h"
#include "Staff.h"

bool isValiable (Course *pCourse) {
    int c = 0;
    while (pCourse->pStudent) {
        c++;
        pCourse->pStudent = pCourse->pStudent->studentNext;
    }
    if (c > pCourse->maxStudent) {
        return false;
    }
    return true;
}
