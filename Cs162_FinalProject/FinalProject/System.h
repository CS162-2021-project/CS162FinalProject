#ifndef _SYSTEM_H_

#define _SYSTEM_H_

#include "Header.h"

int chooseRoleScreen();
bool LogIn(int t);
int yearScreen();
void createYearScreen(Year*& pYear);
int classScreen(Year *& curYear, char* yearName);
void createClassScreen(Class *& pClass, char * yearName);

#endif