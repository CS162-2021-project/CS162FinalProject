#ifndef _COURSE_H_
#define _COURSE_H_

#include<iostream>
#include<fstream>
#include"Header.h"
#include<string.h>

// Create year

void createNewYear(Year*& pHead, char* year);

// Create Semester

void createNewSemester(Semester*& pSemester, char* semester, char* year);

// Create Course

void addNewCourse(Course*& pCourse, char* semester, char* year);

//View list of all course available

void viewListOfCourse(Course* pCourse);

 // Delete Course

void deleteCourse (Course*& pHead, char *courseID);

// Update Course

void updateCourse (Course*& pHead , char* courseID);
  
#endif // !_COURSE_H_
