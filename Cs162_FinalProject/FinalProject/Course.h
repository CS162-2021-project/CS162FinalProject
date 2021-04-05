#ifndef _COURSE_H_
#define _COURSE_H_

#include<iostream>
#include<fstream>
#include"Header.h"

// Input interfare

int inputInterfare();

//Create year semester

void Create_New_Year(Year*& pHead, int& n, char* year);

void createNewSemester(Year*& pHead, int& n, char* semester, char* year);

//Create class

void createNewClass(Year*& pHead, int &n, char* semester, char* year, char* className);
  
#endif // !_COURSE_H_
