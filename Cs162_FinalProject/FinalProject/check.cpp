#include <iostream>
#include <string.h>
#include "Header.h"
#include "Staff.h"

int findHighestMidScore (Scoreboard * & pScr){
    int max = 0;
    while (pScr) {
        if (pScr->midterm > max) {
            max = pScr->midterm;
        }
        pScr = pScr->scoreboardNext;
    }
    return max;
}
