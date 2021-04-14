#include"Header.h"
#include"Course.h"
#include<iostream>
using namespace std;
//unfinished
void viewListOfStudentsInClass(Year* pYear, Class* pClass, char* className) {
	while (pYear) {
		while (pYear->pClass) {
			if (pYear->pClass && strcmp(pYear->pClass->ClassName, className) == 0) {
				while(pYear->pClass->pStudent->)
			}
		}
	}

}