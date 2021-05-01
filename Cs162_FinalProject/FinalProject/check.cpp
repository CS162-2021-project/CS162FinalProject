#include <iostream>
#include <string.h>
#include "Header.h"
#include "Staff.h"

int findLowestMidScore (Scoreboard * & pScr){
    int min = 100000;
    while (pScr) {
        if (pScr->midterm < min) {
            min = pScr->midterm;
        }
        pScr = pScr->scoreboardNext;
    }
    return min;
}
