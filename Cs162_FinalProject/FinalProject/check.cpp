#include <iostream>
#include <string.h>
#include "Header.h"
#include "Staff.h"

int findLowestFinalScore (Scoreboard * & pScr){
    int min = 100000;
    while (pScr) {
        if (pScr->midterm < min) {
            min = pScr->final;
        }
        pScr = pScr->scoreboardNext;
    }
    return min;
}
