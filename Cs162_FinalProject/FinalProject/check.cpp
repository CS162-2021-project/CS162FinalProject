#include <iostream>
#include <string.h>
#include "Header.h"
#include "Staff.h"

void findScore (Scoreboard * & pScr, char* stuID){
    while (pScr->stu && pScr->stu->studentID != stuID) {
        pScr->stu = pScr->stu->studentNext;
    }

    if(pScr->stu != nullptr){
        cout << "Midterm: " << pScr->midterm << endl;
        cout << "Final: " << pScr->final << endl;
        cout << "Bonus: " << pScr->bonus << endl;
        cout << "Total: " << pScr->total << endl;
    }else{
        cout << "Student ID not found." << endl;
    }
}
