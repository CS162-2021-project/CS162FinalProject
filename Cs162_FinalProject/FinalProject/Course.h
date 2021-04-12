#ifndef _COURSE_H_
#define _COURSE_H_

#include<iostream>
#include<fstream>
#include"Header.h"

// Input interfare

int inputInterfare();

// Create year

void createNewYear(Year*& pHead, char* year);

// Create Semester

void createNewSemester(Year*& pHead, int& n, char* semester, char* year);

// Create Course

void addNewCourse(Course*& pHead, int& n, char* semester, char* year);

// Delete Course
 
void deleteCourse (Course*& pHead, char *courseID);

// Update Course

void updateCourse (Course*& pHead);
  
#endif // !_COURSE_H_
