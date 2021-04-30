#include <iostream>
#include "Header.h"
#include "Staff.h"

int daylacheck (Student *pStudent) {
    int countM = 0, countF = 0;
    while (pStudent) {
        if (pStudent->gender == 0)
            countM++;
        else
            countF++;
        pStudent = pStudent->studentNext;
    }
    return count;
}
