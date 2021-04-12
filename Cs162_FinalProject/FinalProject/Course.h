#ifndef _COURSE_H_
#define _COURSE_H_

#include<iostream>
#include<fstream>
#include"Header.h"
#include<string.h>

// Input interfare

int inputInterfare();

// Create year

void createNewYear(Year*& pHead, char* year);

// Create Semester

void createNewSemester(Semester*& pSemester, char* semester, char* year);

// Create Course

void addNewCourse(Course*& pHead, int& n, char* semester, char* year);

//View list of all course available

void viewListOfCourse(Course* pHead);

 // Delete Course

void deleteCourse (Course*& pHead, char *courseID);

// Update Course

void updateCourse (Course*& pHead , char* courseID);
  
#endif // !_COURSE_H_
