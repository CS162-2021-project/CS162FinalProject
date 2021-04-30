#include <iostream>
#include "Header.h"
#include "Staff.h"

int daylacheck (Student *pStudent) {
    int count = 0;
    while (pStudent) {
        count++;
        pStudent = pStudent->studentNext;
    }
    return count;
}
