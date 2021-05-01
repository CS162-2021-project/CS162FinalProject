#include <iostream>
#include <string.h>
#include "Header.h"
#include "Staff.h"

int findHighestFinalScore (Scoreboard * & pScr){
    int max = 0;
    while (pScr) {
        if (pScr->midterm > max) {
            max = pScr->final;
        }
        pScr = pScr->scoreboardNext;
    }
    return max;
}
