#include <iostream>
#include <string.h>
#include "Header.h"
#include "Staff.h"

void findBestStudent (Scoreboard * & pScr){
    int max = 0;
    while (pScr) {
        if (pScr->midterm > max) {
            max = pScr->final;
        }
        pScr = pScr->scoreboardNext;
    }
    cout << "the best student is " << pScr->stu->Name << endl;
}
