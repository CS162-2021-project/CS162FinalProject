#include <iostream>
#include <string.h>
#include "Header.h"
#include "Staff.h"

bool isYounger (Student *pStudent, char *stuID) {
    while (pStudent && pStudent->studentID != stuID) {
        pStudent = pStudent->studentNext;
    }
    if (pStudent->DOB.year > 2002) {
        return true;
    }
    return false;
}
