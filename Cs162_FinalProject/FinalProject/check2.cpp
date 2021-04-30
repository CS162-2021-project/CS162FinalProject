#include <iostream>
#include <string.h>
#include "Header.h"
#include "Staff.h"

bool isInClass (Class pClass, Student *pStudent, char stuID) {
    while (pClass) {
        while (pClass->pStudent) {
            if (strcmp(pClass->pStudent->studentID, stuID) == 0) {
                return true;
            }
            else
                pClass->pStudent = pClass->pStudent->studentNext;
        }
        pClass = pClass->classNext;
    }
    return false;
}
